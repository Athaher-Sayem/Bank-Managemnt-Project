const menus = {
  admin: {
    label: 'Admin path · original console application',
    title: 'Manage the account list.',
    items: ['View and search accounts', 'Add and edit accounts', 'Delete accounts'],
    note: 'These are described in the project’s README. This page does not accept credentials or display records.'
  },
  user: {
    label: 'User path · original console application',
    title: 'Work with a local balance.',
    items: ['Inquire about a balance', 'Deposit into an account', 'Withdraw from an account'],
    note: 'These are menu options in the coursework program, not live banking actions on this page.'
  }
};

const tabs = [...document.querySelectorAll('[data-menu]')];
function selectMenu(name, focus = false) {
  const menu = menus[name];
  if (!menu) return;
  const activeTab = tabs.find(tab => tab.dataset.menu === name);
  tabs.forEach(tab => {
    const selected = tab === activeTab;
    tab.setAttribute('aria-selected', String(selected));
    tab.tabIndex = selected ? 0 : -1;
  });
  document.getElementById('menu-panel').setAttribute('aria-labelledby', activeTab.id);
  document.getElementById('panel-label').textContent = menu.label;
  document.getElementById('panel-title').textContent = menu.title;
  document.getElementById('panel-items').replaceChildren(...menu.items.map(text => {
    const item = document.createElement('li');
    item.textContent = text;
    return item;
  }));
  document.getElementById('panel-note').textContent = menu.note;
  if (focus) activeTab.focus();
}
tabs.forEach((tab, index) => {
  tab.addEventListener('click', () => selectMenu(tab.dataset.menu));
  tab.addEventListener('keydown', event => {
    if (!['ArrowLeft', 'ArrowRight', 'Home', 'End'].includes(event.key)) return;
    event.preventDefault();
    const next = event.key === 'Home' ? 0 : event.key === 'End' ? tabs.length - 1 :
      (index + (event.key === 'ArrowRight' ? 1 : -1) + tabs.length) % tabs.length;
    selectMenu(tabs[next].dataset.menu, true);
  });
});
