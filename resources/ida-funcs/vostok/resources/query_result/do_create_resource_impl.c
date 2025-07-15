void __usercall vostok::resources::query_result::do_create_resource_impl(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  volatile signed __int32 *v3; // edi
  vostok::resources::managed_cook *managed_cook; // eax
  vostok::resources::inplace_managed_cook *inplace_managed_cook; // eax
  vostok::resources::unmanaged_cook *unmanaged_cook; // eax
  vostok::resources::inplace_unmanaged_cook *inplace_unmanaged_cook; // eax
  vostok::resources::query_result *v8; // [esp-4h] [ebp-10h]
  vostok::resources::query_result *v9; // [esp-4h] [ebp-10h]
  vostok::resources::query_result *v10; // [esp-4h] [ebp-10h]
  vostok::resources::query_result *v11; // [esp-4h] [ebp-10h]

  v3 = (volatile signed __int32 *)(a2 + 704);
  _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFFDFFFFF);
  _InterlockedOr((volatile signed __int32 *)(a2 + 704), (unsigned int)&loc_100000);
  managed_cook = vostok::resources::cook_base::find_managed_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( managed_cook )
  {
    vostok::resources::query_result::do_managed_create_resource(
      v8,
      (vostok::resources::query_result *)a2,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)managed_cook);
  }
  else
  {
    inplace_managed_cook = vostok::resources::cook_base::find_inplace_managed_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
    if ( inplace_managed_cook )
    {
      vostok::resources::query_result::do_inplace_managed_create_resource(
        v9,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)a2,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)inplace_managed_cook);
    }
    else
    {
      unmanaged_cook = vostok::resources::cook_base::find_unmanaged_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
      if ( unmanaged_cook )
      {
        vostok::resources::query_result::do_unmanaged_create_resource(v10, a2, unmanaged_cook);
      }
      else
      {
        inplace_unmanaged_cook = vostok::resources::cook_base::find_inplace_unmanaged_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
        if ( inplace_unmanaged_cook )
        {
          vostok::resources::query_result::do_inplace_unmanaged_create_resource(
            inplace_unmanaged_cook,
            v11,
            (vostok::resources::query_result *)a2);
        }
        else
        {
          *(_DWORD *)(a2 + 256) = 0;
          *(_DWORD *)(a2 + 260) = 3;
        }
      }
    }
  }
  _InterlockedAnd(v3, 0xFFEFFFFF);
}
