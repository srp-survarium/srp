void __usercall survarium::options_monitor_index_selector::options_monitor_index_selector(
        survarium::options_monitor_index_selector *this@<ecx>,
        survarium::options_tab *parent_tab@<eax>)
{
  int v2; // esi
  vostok::fixed_string<32> *m_cached_monitors_names; // ebp
  int v5; // ebx
  int v6; // esi
  vostok::memory::doug_lea_allocator *v7; // eax
  int *v8; // eax
  const char **v9; // ecx
  int v10; // edx
  const char **i; // eax
  int v12; // edx
  unsigned __int8 v13; // cl
  int v14; // eax

  v2 = 0;
  survarium::options_item_base::options_item_base(this, "r_monitor_index", parent_tab, 0, string_selector);
  m_cached_monitors_names = this->m_cached_monitors_names;
  this->m_values = 0;
  this->m_values_count = 0;
  this->__vftable = (survarium::options_monitor_index_selector_vtbl *)&survarium::options_monitor_index_selector::`vftable';
  `vector constructor iterator'(
    (char *)this->m_cached_monitors_names,
    0x2Cu,
    6,
    (void *(__thiscall *)(void *))vostok::fixed_string<32>::fixed_string<32>);
  v5 = 6;
  do
  {
    vostok::buffer_string::assignf(m_cached_monitors_names++, "%d", v2++);
    --v5;
  }
  while ( v5 );
  v6 = vostok::render::g_num_monitors;
  v7 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v8 = (int *)vostok::memory::doug_lea_allocator::malloc_impl(v7, 4 * v6 + 8);
  *v8++ = v6;
  v9 = (const char **)(v8 + 1);
  v10 = (int)&v8[v6 + 1];
  *v8 = 4;
  for ( i = v9; i != (const char **)v10; ++i )
  {
    if ( i )
      *i = 0;
  }
  v12 = vostok::render::g_num_monitors;
  this->m_values = v9;
  v13 = 0;
  this->m_values_count = v12;
  if ( v12 > 0 )
  {
    v14 = 0;
    do
    {
      ++v13;
      this->m_values[v14] = this->m_cached_monitors_names[v14].m_begin;
      v14 = v13;
    }
    while ( v13 < v12 );
  }
}
