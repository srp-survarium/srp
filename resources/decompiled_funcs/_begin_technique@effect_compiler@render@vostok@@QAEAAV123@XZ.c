vostok::render::effect_compiler *__usercall vostok::render::effect_compiler::begin_technique@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>)
{
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // ecx
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // ebx

  if ( !*(_BYTE *)(a2 + 37008) )
  {
    v2 = *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36984);
    v3 = *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36980);
    if ( v3 != v2 )
    {
      v4 = stlp_std::priv::__copy<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,int>(
             v2,
             v3,
             *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36984));
      stlp_std::_Destroy_Range<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>(
        v4,
        *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36984));
      *(_DWORD *)(a2 + 36984) = v4;
    }
    *(_DWORD *)(a2 + 37004) = 0;
  }
  return (vostok::render::effect_compiler *)a2;
}
