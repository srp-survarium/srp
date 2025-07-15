void __fastcall vostok::render::skeleton_render_model_instance::update_render_matrices(
        int a1,
        const vostok::math::float4x4 *matrices,
        const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *this,
        const vostok::math::float4x4 *shadow_matrices,
        boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *count)
{
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v5; // ecx
  int v6; // eax
  int v7; // edx
  vostok::math::float4x4 *v8; // eax
  vostok::math::float4x4 *v9; // edi
  bool v10; // zf
  int v11; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v12; // edx
  vostok::math::float4x4 *v13; // esi
  vostok::math::float4x4 *v14; // edi
  vostok::render::update_bones_subscriber *i; // esi
  int v16; // [esp+10h] [ebp-90h]
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v17; // [esp+14h] [ebp-8Ch]
  int v18; // [esp+18h] [ebp-88h]
  const vostok::math::float4x4 *v19; // [esp+1Ch] [ebp-84h]
  vostok::math::float4x4 v20; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v21; // [esp+60h] [ebp-40h] BYREF

  v5 = count;
  if ( count )
  {
    v6 = 0;
    v7 = (char *)matrices - (char *)shadow_matrices;
    v16 = 0;
    v18 = v7;
    v17 = count;
    while ( 1 )
    {
      qmemcpy(
        (char *)this[12].m_free_list_head.pointer + v6,
        (char *)this[183].m_on_out_of_memory.functor.vostok_pointer_size_alignment[5] + v6,
        0x40u);
      v19 = (const vostok::math::float4x4 *)((char *)shadow_matrices + v6);
      vostok::math::mul4x3(
        (const vostok::math::float4x4 *)((char *)shadow_matrices + v6 + v7),
        (const vostok::math::float4x4 *)(v6
                                       + *((_DWORD *)this[525].m_on_out_of_memory.functor.vostok_pointer_size_alignment[3]
                                         + 80)),
        &v20);
      qmemcpy(
        (char *)this[183].m_on_out_of_memory.functor.vostok_pointer_size_alignment[5] + v16,
        vostok::math::transpose(&v20, &v21),
        0x40u);
      vostok::math::mul4x3(
        v19,
        (const vostok::math::float4x4 *)(v16
                                       + *((_DWORD *)this[525].m_on_out_of_memory.functor.vostok_pointer_size_alignment[3]
                                         + 80)),
        &v20);
      v8 = vostok::math::transpose(&v20, &v21);
      v9 = (vostok::math::float4x4 *)((char *)this[354].m_on_out_of_memory.functor.bound_memfunc_ptr.obj_ptr + v16);
      v16 += 64;
      v10 = v17 == (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)1;
      v17 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)((char *)v17 - 1);
      qmemcpy(v9, v8, sizeof(vostok::math::float4x4));
      if ( v10 )
        break;
      v7 = v18;
      v6 = v16;
    }
    v5 = count;
  }
  if ( LOBYTE(this[525].m_free_list_head.pointer) && v5 )
  {
    v11 = 0;
    v12 = v5;
    do
    {
      v13 = (vostok::math::float4x4 *)((char *)this[183].m_on_out_of_memory.functor.vostok_pointer_size_alignment[5]
                                     + v11);
      v14 = (vostok::math::float4x4 *)((char *)this[12].m_free_list_head.pointer + v11);
      v11 += 64;
      v12 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)((char *)v12 - 1);
      qmemcpy(v14, v13, sizeof(vostok::math::float4x4));
      v5 = 0;
    }
    while ( v12 );
    LOBYTE(this[525].m_free_list_head.pointer) = 0;
  }
  for ( i = (vostok::render::update_bones_subscriber *)this[526].m_on_out_of_memory.functor.vostok_pointer_size_alignment[5];
        i;
        i = i->next )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(v5, i, this);
  }
}
