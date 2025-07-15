char __usercall vostok::render::remove_texture_predicate::operator()@<al>(
        const vostok::render::effect_compiler::texture_query_desc *desc@<eax>)
{
  char *m_begin; // esi
  vostok::fixed_string<260> *m_end; // ebx
  vostok::fixed_vector<vostok::fixed_string<260>,2048> *p_m_loaded_texture_names; // edi
  vostok::fixed_string<260> *v4; // eax
  vostok::buffer_vector<vostok::fixed_string<260> > *v5; // ecx
  vostok::fixed_string<260> *v7; // [esp-4h] [ebp-124h]
  vostok::fixed_string<260> v8; // [esp+Ch] [ebp-114h] BYREF
  char *v9; // [esp+11Ch] [ebp-4h] BYREF

  m_begin = desc->m_query_short_path.m_begin;
  m_end = vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_loaded_texture_names.m_end;
  p_m_loaded_texture_names = &vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_loaded_texture_names;
  v4 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst->m_loaded_texture_names.m_begin;
  v9 = m_begin;
  if ( stlp_std::priv::__find<vostok::fixed_string<260> *,char const *>(v4, m_end, (const char **)&v9) != m_end )
    return 1;
  vostok::fixed_string<260>::fixed_string<260>(v7, &v8, m_begin);
  vostok::buffer_vector<vostok::fixed_string<260>>::push_back(v5, (int)p_m_loaded_texture_names, &v8);
  return 0;
}
