void __thiscall vostok::sound::encoded_sound_with_qualities::decrease_quality(
        vostok::sound::encoded_sound_with_qualities *this,
        unsigned int new_best_quality)
{
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *m_qualities; // esi
  survarium::player *m_object; // edi
  vostok::threading::simple_lock *v5; // eax
  vostok::resources::resource_link *m_first; // eax
  unsigned int quality_value; // edi
  int v8; // [esp+8h] [ebp-10h]
  vostok::threading::simple_lock::mutex_raii v9; // [esp+Ch] [ebp-Ch] BYREF

  m_qualities = (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)this->m_qualities;
  v9.lock = (const vostok::threading::simple_lock *)2;
  do
  {
    m_object = m_qualities->m_object;
    if ( this == (vostok::sound::encoded_sound_with_qualities *)-36 )
      v5 = 0;
    else
      v5 = &this->m_children_resources.vostok::threading::simple_lock;
    *(_DWORD *)&v9.locked = v5;
    vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, (int)v5);
    m_first = this->m_children_resources.m_first;
    v9.locked = 1;
    while ( 1 )
    {
      if ( !m_first )
      {
        vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v9);
        quality_value = 0;
        goto LABEL_10;
      }
      if ( m_first->resource == m_object )
        break;
      m_first = m_first->next_link;
    }
    quality_value = m_first->quality_value;
    vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v9);
LABEL_10:
    if ( quality_value != -1 && quality_value < new_best_quality )
    {
      vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
        (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)this,
        m_qualities);
      vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
        m_qualities,
        0);
    }
    m_qualities += 2;
    --v8;
  }
  while ( v8 );
}
