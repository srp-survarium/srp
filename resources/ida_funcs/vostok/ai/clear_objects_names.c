void __cdecl vostok::ai::clear_objects_names(survarium::game_camera *objects)
{
  survarium::game_camera *v1; // ecx
  int i; // [esp+30h] [ebp-4h]

  v1 = objects;
  for ( i = ((signed int)(LODWORD(objects->m_inverted_view_matrix.i.x) - (unsigned int)objects->__vftable) >> 2) - 1;
        i >= 0;
        --i )
  {
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,char,vostok::memory::detail::call_destructor_predicate>(
      vostok::ai::g_allocator,
      (char **)&objects->get_projection_matrix + i);
  }
}
