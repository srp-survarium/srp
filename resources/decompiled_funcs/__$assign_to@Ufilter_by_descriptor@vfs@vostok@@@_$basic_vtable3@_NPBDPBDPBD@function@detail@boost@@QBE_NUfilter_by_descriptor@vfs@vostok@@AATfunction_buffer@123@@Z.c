char __thiscall boost::detail::function::basic_vtable3<bool,char const *,char const *,char const *>::assign_to<vostok::vfs::filter_by_descriptor>(
        boost::detail::function::basic_vtable3<bool,char const *,char const *,char const *> *this,
        vostok::vfs::filter_by_descriptor f,
        boost::detail::function::function_buffer *functor)
{
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > v; // [esp+Ch] [ebp-14h] BYREF
  char v6; // [esp+1Eh] [ebp-2h]
  char v7; // [esp+1Fh] [ebp-1h]

  v7 = 0;
  LODWORD(v.f_.f_) = f;
  boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>(&v);
  if ( survarium::generate_shaders_world::is_loading() )
  {
    return 0;
  }
  else
  {
    v6 = 0;
    HIBYTE(v.f_.f_) = 0;
    v.l_.a1_.t_ = (vostok::sound::sound_environment_cook *)v.f_.f_;
    v.l_.a3_.t_ = (vostok::math::float4x4 *)operator new(4u, (void *)functor);
    if ( v.l_.a3_.t_ )
      LODWORD(v.l_.a3_.t_->i.x) = v.l_.a1_.t_;
    return 1;
  }
}
