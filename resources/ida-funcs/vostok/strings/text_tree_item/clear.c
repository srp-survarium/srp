void __thiscall vostok::strings::text_tree_item::clear(vostok::strings::text_tree_item *this)
{
  vostok::intrusive_list<vostok::strings::text_tree_item_base,vostok::strings::text_tree_item *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_sub_items; // esi
  vostok::strings::text_tree_item *i; // edi
  vostok::strings::text_tree_item *v4; // ecx
  void (__stdcall *v5)(LPCRITICAL_SECTION); // edi
  vostok::threading::mutex *v6; // ecx
  vostok::strings::text_tree_column_item *m_first; // eax
  vostok::strings::text_tree_column_item *next; // ecx
  LPCRITICAL_SECTION lpCriticalSectionb; // [esp+10h] [ebp-4h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+10h] [ebp-4h]
  _RTL_CRITICAL_SECTION *lpCriticalSectiona; // [esp+10h] [ebp-4h]

  p_m_sub_items = &this->m_sub_items;
  if ( this->m_sub_items.m_first )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)this,
      (_RTL_CRITICAL_SECTION *)&this->m_sub_items.vostok::threading::mutex);
    for ( i = p_m_sub_items->m_first; i; i = (vostok::strings::text_tree_item *)lpCriticalSectionb )
    {
      lpCriticalSectionb = (LPCRITICAL_SECTION)i->m_next_brother;
      vostok::strings::text_tree_item::clear(i);
      vostok::strings::text_tree_item::~text_tree_item(v4, (int)i);
    }
    v5 = LeaveCriticalSection;
    LeaveCriticalSection((LPCRITICAL_SECTION)&p_m_sub_items->vostok::threading::mutex);
  }
  else
  {
    v5 = LeaveCriticalSection;
  }
  if ( p_m_sub_items )
  {
    lpCriticalSection = (_RTL_CRITICAL_SECTION *)&p_m_sub_items->vostok::threading::mutex;
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)this,
      (_RTL_CRITICAL_SECTION *)&p_m_sub_items->vostok::threading::mutex);
  }
  else
  {
    lpCriticalSection = 0;
    vostok::threading::mutex::lock((vostok::threading::mutex *)this, 0);
  }
  p_m_sub_items->m_first = 0;
  p_m_sub_items->m_last = 0;
  p_m_sub_items->m_size = 0;
  v5(lpCriticalSection);
  if ( this->m_column_items.m_first )
  {
    vostok::threading::mutex::lock(v6, (_RTL_CRITICAL_SECTION *)&this->m_column_items.vostok::threading::mutex);
    m_first = this->m_column_items.m_first;
    if ( m_first )
    {
      do
      {
        next = m_first->next;
        if ( m_first->value )
          m_first->value = 0;
        m_first = next;
      }
      while ( next );
    }
    v5((LPCRITICAL_SECTION)&this->m_column_items.vostok::threading::mutex);
  }
  if ( this == (vostok::strings::text_tree_item *)-56 )
  {
    lpCriticalSectiona = 0;
    vostok::threading::mutex::lock(v6, 0);
  }
  else
  {
    lpCriticalSectiona = (_RTL_CRITICAL_SECTION *)&this->m_column_items.vostok::threading::mutex;
    vostok::threading::mutex::lock(v6, (_RTL_CRITICAL_SECTION *)&this->m_column_items.vostok::threading::mutex);
  }
  this->m_column_items.m_first = 0;
  this->m_column_items.m_last = 0;
  this->m_column_items.m_size = 0;
  v5(lpCriticalSectiona);
  if ( this->m_column_value )
    this->m_column_value = 0;
}
