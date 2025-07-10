BOOL __thiscall vostok::render::effect_lighting_stage_default_materials::should_recompile_when_global_changes(
        vostok::render::effect_lighting_stage_default_materials *this,
        const vostok::render::vector<vostok::fs_new::virtual_path_string> *in_changed_defines)
{
  return stlp_std::priv::__find<vostok::fs_new::virtual_path_string const *,char const [23]>(
           in_changed_defines->_M_impl._M_start,
           in_changed_defines->_M_impl._M_finish) != in_changed_defines->_M_impl._M_finish
      || stlp_std::priv::__find<vostok::fs_new::virtual_path_string const *,char const [38]>(
           in_changed_defines->_M_impl._M_start,
           in_changed_defines->_M_impl._M_finish) != in_changed_defines->_M_impl._M_finish;
}
