void __usercall vostok::render::light_props::load_light_props(
        vostok::render::light_props *this@<ecx>,
        vostok::configs::binary_config_value *cfg@<eax>)
{
  vostok::render::load_props_impl<vostok::configs::binary_config_value>(this, cfg);
}
