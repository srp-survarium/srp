void __thiscall stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>(
        stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char> > *this,
        unsigned int __n,
        const unsigned __int8 *__val,
        const stlp_std::allocator<unsigned char> *__a)
{
  const stlp_std::allocator<unsigned char> *v4; // [esp+0h] [ebp-2Ch]
  int i; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *M_start; // [esp+14h] [ebp-18h]
  unsigned __int8 *v8; // [esp+1Ch] [ebp-10h]

  stlp_std::priv::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>(
    this,
    __n,
    v4);
  v8 = &this->_M_start[__n];
  M_start = this->_M_start;
  for ( i = __n; i > 0; --i )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *M_start++ = *__val;
  }
  this->_M_finish = v8;
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __x)
{
  const stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *v3; // ebx
  vostok::memory::base_allocator *v4; // eax
  int v5; // edi
  int *p_x; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *M_finish; // edi
  unsigned __int8 *M_start; // ebx
  unsigned int v10; // edi
  int v11; // eax
  int v12; // [esp+8h] [ebp-4h] BYREF

  v3 = (const stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *)__x;
  v4 = *(vostok::memory::base_allocator **)(__x + 8);
  v5 = (*(_DWORD *)(__x + 4) - *(_DWORD *)__x) >> 1;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = (unsigned __int8 *)v4;
  a2[3] = 0;
  v12 = v5;
  __x = 1;
  p_x = &__x;
  if ( v5 )
    p_x = &v12;
  v7 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                            a2[2],
                            0,
                            2 * *p_x);
  *a2 = v7;
  a2[1] = v7;
  a2[3] = &v7[2 * v5];
  M_finish = (unsigned __int8 *)v3->_M_finish;
  M_start = (unsigned __int8 *)v3->_M_start;
  if ( M_finish != M_start )
  {
    v10 = M_finish - M_start;
    memcpy(v7, M_start, v10);
    v7 = (unsigned __int8 *)(v10 + v11);
  }
  a2[1] = v7;
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int __n,
        unsigned int *__val,
        const vostok::ai::std_allocator<unsigned int> *__a)
{
  stlp_std::priv::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>(
    this,
    __n,
    __a);
  this->_M_finish = stlp_std::priv::__uninitialized_fill_n<unsigned int *,unsigned int,unsigned int>(
                      this->_M_start,
                      __n,
                      __val);
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_Impl_vector<void *,vostok::render::std_allocator<void *>>(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        const stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *__x)
{
  signed int v3; // edi
  unsigned __int8 *v4; // eax
  void **M_finish; // edi
  unsigned __int8 *M_start; // ebx
  unsigned int v7; // edi
  int v8; // eax
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v9; // [esp+0h] [ebp-8h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v3 >>= 2;
  a2[2] = 0;
  v4 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                            v3,
                            v9);
  *a2 = v4;
  a2[1] = v4;
  a2[2] = &v4[4 * v3];
  M_finish = __x->_M_finish;
  M_start = (unsigned __int8 *)__x->_M_start;
  if ( M_finish != __x->_M_start )
  {
    v7 = (char *)M_finish - (char *)M_start;
    memcpy(v4, M_start, v7);
    v4 = (unsigned __int8 *)(v7 + v8);
  }
  a2[1] = v4;
}


void __usercall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
        survarium::vector<vostok::resources::request> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
}


void __usercall stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_Impl_vector<void *,vostok::vectora_allocator<void *>>(
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *this@<eax>,
        const vostok::vectora_allocator<void *> *__a@<edx>)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage.m_allocator = __a->m_allocator;
  this->_M_end_of_storage._M_data = 0;
}


void __thiscall stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
        stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *this,
        const vostok::vectora_allocator<void const *> *__a)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage.m_allocator = __a->m_allocator;
  this->_M_end_of_storage._M_data = 0;
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(
        stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *this,
        const stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *__x)
{
  int v2; // eax
  vostok::sound::sound_voice_params *M_start; // [esp+0h] [ebp-34h]
  unsigned __int8 *src; // [esp+Ch] [ebp-28h]
  vostok::sound::sound_voice_params *M_finish; // [esp+10h] [ebp-24h]
  vostok::vectora_allocator<vostok::sound::sound_voice_params> __a; // [esp+30h] [ebp-4h] BYREF

  __a.m_allocator = __x->_M_end_of_storage.m_allocator;
  stlp_std::priv::_Vector_base<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_Vector_base<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(
    this,
    __x->_M_finish - __x->_M_start,
    &__a);
  M_finish = __x->_M_finish;
  src = (unsigned __int8 *)__x->_M_start;
  if ( M_finish == __x->_M_start )
  {
    M_start = this->_M_start;
  }
  else
  {
    memcpy((unsigned __int8 *)this->_M_start, src, (char *)M_finish - (char *)src);
    M_start = (vostok::sound::sound_voice_params *)((char *)M_finish - (char *)src + v2);
  }
  this->_M_finish = M_start;
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>(
        stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__x)
{
  int v3; // ecx
  int v4; // edi
  unsigned __int8 *v5; // eax
  vostok::render::streaming_texture_instance *M_finish; // edi
  unsigned __int8 *M_start; // ebx
  unsigned int v8; // edi
  int v9; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v10; // [esp+0h] [ebp-8h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v4 = v3 / 24;
  a2[2] = 0;
  v5 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                            v3 / 24,
                            v10);
  *a2 = v5;
  a2[1] = v5;
  a2[2] = &v5[24 * v4];
  M_finish = __x->_M_finish;
  M_start = (unsigned __int8 *)__x->_M_start;
  if ( M_finish != __x->_M_start )
  {
    v8 = (char *)M_finish - (char *)M_start;
    memcpy(v5, M_start, v8);
    v5 = (unsigned __int8 *)(v8 + v9);
  }
  a2[1] = v5;
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
        stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        const stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *__x)
{
  signed int v3; // esi
  unsigned __int8 *v4; // eax
  vostok::math::float4x4 *M_finish; // esi
  unsigned __int8 *M_start; // ebx
  unsigned int v7; // esi
  int v8; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex> > *v9; // [esp+0h] [ebp-8h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v3 >>= 6;
  a2[2] = 0;
  v4 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::allocate(
                            v3,
                            v9);
  *a2 = v4;
  a2[1] = v4;
  a2[2] = &v4[64 * v3];
  M_finish = __x->_M_finish;
  M_start = (unsigned __int8 *)__x->_M_start;
  if ( M_finish != __x->_M_start )
  {
    v7 = (char *)M_finish - (char *)M_start;
    memcpy(v4, M_start, v7);
    v4 = (unsigned __int8 *)(v7 + v8);
  }
  a2[1] = v4;
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *__x)
{
  const vostok::ai::planning::pddl_world_state_property_impl *__val; // [esp+8h] [ebp-58h]
  int i; // [esp+30h] [ebp-30h]
  vostok::ai::planning::pddl_world_state_property_impl *__p; // [esp+34h] [ebp-2Ch]
  vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> __a; // [esp+5Fh] [ebp-1h] BYREF

  stlp_std::priv::_Vector_base<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_Vector_base<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(
    this,
    __x->_M_finish - __x->_M_start,
    &__a);
  __val = __x->_M_start;
  __p = this->_M_start;
  for ( i = __x->_M_finish - __x->_M_start; i > 0; --i )
    stlp_std::_Param_Construct<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::planning::pddl_world_state_property_impl>(
      __p++,
      __val++);
  this->_M_finish = __p;
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>(
        stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *this@<ecx>,
        vostok::render::shader_constant **a2@<esi>,
        const stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__x)
{
  int v3; // ecx
  int v4; // edi
  vostok::render::shader_constant *v5; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v6; // [esp+0h] [ebp-8h]
  const stlp_std::random_access_iterator_tag *v7; // [esp+0h] [ebp-8h]
  int *v8; // [esp+4h] [ebp-4h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v4 = v3 / 24;
  a2[2] = 0;
  v5 = (vostok::render::shader_constant *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                                            v3 / 24,
                                            v6);
  *a2 = v5;
  a2[1] = v5;
  a2[2] = &v5[v4];
  a2[1] = stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
            __x->_M_start,
            __x->_M_finish,
            v5,
            v7,
            v8);
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>(
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *this@<ecx>,
        vostok::fs_new::virtual_path_string **a2@<edi>,
        const stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *__x)
{
  int v3; // ecx
  int v4; // esi
  vostok::fs_new::virtual_path_string *v5; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::texture_named_instance *,vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance> > *v6; // [esp+0h] [ebp-8h]
  const stlp_std::random_access_iterator_tag *v7; // [esp+0h] [ebp-8h]
  int *v8; // [esp+4h] [ebp-4h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v4 = v3 / 276;
  a2[2] = 0;
  v5 = (vostok::fs_new::virtual_path_string *)stlp_std::priv::_STLP_alloc_proxy<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::allocate(
                                                v3 / 276,
                                                v6);
  *a2 = v5;
  a2[1] = v5;
  a2[2] = &v5[v4];
  a2[1] = stlp_std::priv::__ucopy<vostok::fs_new::virtual_path_string const *,vostok::fs_new::virtual_path_string *,int>(
            __x->_M_start,
            __x->_M_finish,
            v5,
            v7,
            v8);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *__x)
{
  vostok::ai::std_allocator<vostok::ai::planning::world_state_property> __a; // [esp+2Bh] [ebp-1h] BYREF

  stlp_std::priv::_Vector_base<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_Vector_base<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
    this,
    __x->_M_finish - __x->_M_start,
    &__a);
  this->_M_finish = (vostok::ai::planning::world_state_property *)stlp_std::priv::__ucopy_trivial(
                                                                    (unsigned __int8 *)__x->_M_start,
                                                                    (unsigned __int8 *)__x->_M_finish,
                                                                    (unsigned __int8 *)this->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
        stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *this,
        const vostok::ai::std_allocator<vostok::ai::planning::specified_action> *__a)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage._M_data = 0;
}
