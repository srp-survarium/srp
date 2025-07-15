void __thiscall vostok::sound::atomic_half3::set(vostok::sound::atomic_half3 *this, vostok::math::half3 *val, int a3)
{
  __int64 exchange; // [esp+8h] [ebp-8h] BYREF

  vostok::sound::atomic_half3::atomic_half3(this, &exchange);
  LODWORD(exchange) = *(_DWORD *)a3;
  WORD2(exchange) = *(_WORD *)(a3 + 4);
  vostok::threading::interlocked_exchange((volatile __int64 *)val, exchange);
}
