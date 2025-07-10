const vostok::ai::sound_item **__cdecl stlp_std::priv::__median<survarium::anomaly_state *,bool (__cdecl *)(survarium::anomaly_state *,survarium::anomaly_state *)>(
        const vostok::ai::sound_item **__a,
        const vostok::ai::sound_item **__b,
        const vostok::ai::sound_item **__c,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  if ( __comp(*__a, *__b) )
  {
    if ( __comp(*__b, *__c) )
    {
      return __b;
    }
    else if ( __comp(*__a, *__c) )
    {
      return __c;
    }
    else
    {
      return __a;
    }
  }
  else if ( __comp(*__a, *__c) )
  {
    return __a;
  }
  else if ( __comp(*__b, *__c) )
  {
    return __c;
  }
  else
  {
    return __b;
  }
}
