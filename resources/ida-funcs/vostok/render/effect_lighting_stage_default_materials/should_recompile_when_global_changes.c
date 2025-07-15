BOOL __thiscall vostok::render::effect_lighting_stage_default_materials::should_recompile_when_global_changes(
        vostok::render::effect_lighting_stage_default_materials *this,
        const vostok::fixed_vector<vostok::fs_new::virtual_path_string,32> *in_changed_defines)
{
  vostok::fs_new::virtual_path_string *m_end; // esi
  vostok::fs_new::virtual_path_string *m_begin; // edi

  m_end = in_changed_defines->m_end;
  m_begin = in_changed_defines->m_begin;
  return stlp_std::priv::__find<vostok::fs_new::virtual_path_string const *,char const [23]>(
           in_changed_defines->m_begin,
           m_end) != m_end
      || stlp_std::priv::__find<vostok::fs_new::virtual_path_string const *,char const [38]>(m_begin, m_end) != m_end;
}
