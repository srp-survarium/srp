void __thiscall survarium::shotgun_weapon_reload_state_cook::deallocate_resource(
        survarium::shotgun_weapon_reload_state_cook *this,
        void *buffer)
{
  void *v2; // esi

  if ( buffer )
  {
    v2 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v2, buffer);
  }
}
