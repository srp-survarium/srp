survarium::free_fly_camera *__thiscall survarium::free_fly_camera::`vector deleting destructor'(
        survarium::free_fly_camera *this,
        char a2)
{
  int *M_start; // eax
  void *v4; // esi
  int *v5; // eax
  void *v6; // esi

  M_start = this->m_mouse_events._M_impl._M_start;
  if ( M_start )
  {
    v4 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v4, M_start);
  }
  v5 = this->m_keyb_events._M_impl._M_start;
  if ( v5 )
  {
    v6 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v6, v5);
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::free_fly_camera *__thiscall survarium::free_fly_camera::`vector deleting destructor'(char *this, char a2)
{
  return survarium::free_fly_camera::`vector deleting destructor'((survarium::free_fly_camera *)(this - 84), a2);
}
