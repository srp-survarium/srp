const boost::reference_wrapper<vostok::configs::binary_config_value const > *__cdecl boost::cref<vostok::configs::binary_config_value>(
        const boost::reference_wrapper<vostok::configs::binary_config_value const > *result,
        boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *t)
{
  result->t_ = (const vostok::configs::binary_config_value *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>(t);
  return result;
}
