bool __usercall vostok::resources::query_result::retry_action_that_caused_out_of_memory@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  vostok::resources::query_result *v4; // ecx
  vostok::resources::reallocating_bool v6; // [esp+0h] [ebp-10h]
  bool out_finished_create; // [esp+Fh] [ebp-1h] BYREF

  *(_DWORD *)(a2 + 256) = 0;
  ++*(_BYTE *)(a2 + 337);
  *(_DWORD *)(a2 + 324) = 0;
  v3 = *(_DWORD *)(a2 + 320);
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  out_finished_create = 1;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 728), 1u);
  switch ( v3 )
  {
    case 1:
      _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFFFFBFFF);
      vostok::resources::query_result::translate_query_if_needed((vostok::resources::query_result *)(a2 + 704), a2);
      break;
    case 2:
      vostok::resources::query_result::do_create_resource((vostok::resources::query_result *)a2, &out_finished_create);
      goto LABEL_9;
    case 3:
      vostok::resources::allocate_functionality::prepare_raw_resource(
        (vostok::resources::query_result *)a2,
        (vostok::resources::allocate_functionality *)1,
        v6);
      break;
    default:
      vostok::resources::query_result::prepare_final_resource(
        (vostok::resources::query_result *)(a2 + 728),
        (vostok::resources::query_result *)a2);
      break;
  }
  out_finished_create = *(_DWORD *)(a2 + 320) == 0;
LABEL_9:
  if ( out_finished_create )
  {
    v4 = (vostok::resources::query_result *)(a2 + 704);
    _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFFBFFFFF);
  }
  vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v4, a2);
  return out_finished_create;
}
