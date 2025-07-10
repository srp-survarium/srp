void __cdecl stlp_std::_Param_Construct<vostok::logging::initiator_filter,vostok::logging::initiator_filter>(
        vostok::logging::initiator_filter *__p,
        const vostok::logging::initiator_filter *__val)
{
  vostok::logging::initiator_filter *v2; // [esp+1Ch] [ebp-8h]

  v2 = (vostok::logging::initiator_filter *)operator new(0x3Cu, __p);
  if ( v2 )
    vostok::logging::initiator_filter::initiator_filter(v2, __val);
}
