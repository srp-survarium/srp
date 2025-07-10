void __thiscall vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
        vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *this,
        vostok::vfs::mounter *object)
{
  survarium::game_camera *v2; // ecx
  vostok::vfs::mounter_base *v3; // [esp+4h] [ebp-38h]
  vostok::vfs::mounter_base *v4; // [esp+8h] [ebp-34h]
  vostok::vfs::mounter_base *v5; // [esp+14h] [ebp-28h]
  survarium::game_camera *v6; // [esp+18h] [ebp-24h]
  vostok::vfs::mounter_base *v7; // [esp+1Ch] [ebp-20h]
  vostok::vfs::mounter_base *v8; // [esp+20h] [ebp-1Ch]
  vostok::vfs::mounter *next; // [esp+2Ch] [ebp-10h]
  vostok::vfs::mounter *prev; // [esp+30h] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+34h] [ebp-8h] BYREF

  if ( this->m_first )
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->m_policy,
      (int)&raii);
    if ( object )
      v8 = &object->vostok::vfs::mounter_base;
    else
      v8 = 0;
    prev = v8->prev;
    if ( object )
      v7 = &object->vostok::vfs::mounter_base;
    else
      v7 = 0;
    next = v7->next;
    if ( object )
      v6 = (survarium::game_camera *)&object->vostok::vfs::mounter_base;
    else
      v6 = 0;
    v6->__vftable = 0;
    if ( object )
      v5 = &object->vostok::vfs::mounter_base;
    else
      v5 = 0;
    v5->next = 0;
    if ( prev )
    {
      v2 = (survarium::game_camera *)&prev->vostok::vfs::mounter_base;
      prev->next = next;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(v6);
      this->m_first = next;
    }
    if ( next )
    {
      next->prev = prev;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize(v2);
      this->m_last = prev;
    }
    if ( object )
      v4 = &object->vostok::vfs::mounter_base;
    else
      v4 = 0;
    v4->prev = 0;
    if ( object )
      v3 = &object->vostok::vfs::mounter_base;
    else
      v3 = 0;
    v3->next = 0;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)v3,
      (int)&raii);
  }
}
