vostok::render::res_shader_technique *__fastcall vostok::render::effect_manager::create_effect_technique(
        vostok::render::effect_manager *this,
        int a2,
        vostok::render::res_shader_technique *element)
{
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_begin; // ecx
  stlp_std::priv::_Rb_tree_node_base *v5; // esi
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::res_shader_technique *v10; // edi
  stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *> > *v11; // ecx
  stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *> > *v12; // [esp-8h] [ebp-28h]
  stlp_std::priv::_Rb_tree_node_base v13; // [esp-4h] [ebp-24h]
  const char *v14; // [esp+0h] [ebp-20h]
  const char *v15; // [esp+4h] [ebp-1Ch]
  unsigned int v16; // [esp+8h] [ebp-18h]
  vostok::render::res_shader_technique *__x; // [esp+Ch] [ebp-14h] BYREF
  stlp_std::priv::_Rb_tree_iterator<vostok::render::res_shader_technique *,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *> > v18; // [esp+10h] [ebp-10h] BYREF
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32> *other; // [esp+14h] [ebp-Ch]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_shader_technique *,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *> >,bool> *result; // [esp+18h] [ebp-8h] BYREF

  m_begin = element->m_passes.m_begin;
  other = &element->m_passes;
  if ( m_begin == element->m_passes.m_end )
    return 0;
  v5 = (stlp_std::priv::_Rb_tree_node_base *)(a2 + 18244);
  __x = element;
  result = (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_shader_technique *,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *> >,bool> *)(a2 + 18244);
  stlp_std::set<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::std_allocator<vostok::render::res_shader_technique *>>::find<vostok::render::res_shader_technique const *>(
    &__x,
    (stlp_std::set<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::std_allocator<vostok::render::res_shader_technique *> > *)(a2 + 18244),
    &v18);
  if ( v18._M_node != v5 )
    return *(vostok::render::res_shader_technique **)&v18._M_node[1]._M_color;
  v6 = vostok::render::g_allocator;
  v7 = type_info::raw_name(&vostok::render::res_shader_technique `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x98u, v7, v14, v15, v16);
  if ( v9 )
  {
    *(_DWORD *)v9 = 0;
    *((_DWORD *)v9 + 2) = v9 + 20;
    *((_DWORD *)v9 + 3) = v9 + 20;
    *((_DWORD *)v9 + 4) = v9 + 148;
    v9[148] = 0;
    v10 = (vostok::render::res_shader_technique *)v9;
  }
  else
  {
    v10 = 0;
  }
  v10->m_flags = element->m_flags;
  __x = v10;
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>::operator=(
    &v10->m_passes,
    other);
  *(_DWORD *)&v13._M_color = &__x;
  v12 = (stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *> > *)result;
  v10->m_registered = 1;
  stlp_std::priv::_Rb_tree<vostok::render::res_shader_technique *,vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique>,vostok::render::res_shader_technique *,stlp_std::priv::_Identity<vostok::render::res_shader_technique *>,stlp_std::priv::_SetTraitsT<vostok::render::res_shader_technique *>,vostok::render::std_allocator<vostok::render::res_shader_technique *>>::insert_unique(
    v11,
    (int)&result,
    v12,
    v13);
  return v10;
}
