void __thiscall vostok::render::user_render_model_instance::get_surfaces(
        vostok::render::user_render_model_instance *this,
        const vostok::math::float4x4 *mat_vp,
        const vostok::math::float3 *view_pos,
        vostok::render::vector<vostok::render::render_surface_instance *> *dest,
        bool visible_only,
        unsigned __int8 __formal,
        unsigned int surface_flags)
{
  void **M_finish; // eax
  vostok::render::render_surface_instance *p_m_surface_instance; // ecx
  bool v9; // [esp+0h] [ebp-8h]
  void *__x; // [esp+4h] [ebp-4h] BYREF

  M_finish = dest->_M_impl._M_finish;
  p_m_surface_instance = &this->m_surface_instance;
  __x = p_m_surface_instance;
  if ( M_finish == dest->_M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&__x,
      (int)dest,
      M_finish,
      &__x,
      (const stlp_std::__true_type *)1,
      1,
      v9);
  }
  else
  {
    *M_finish = p_m_surface_instance;
    ++dest->_M_impl._M_finish;
  }
}
