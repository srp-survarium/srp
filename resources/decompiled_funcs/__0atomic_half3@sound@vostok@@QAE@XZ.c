void __thiscall vostok::sound::atomic_half3::atomic_half3(vostok::sound::atomic_half3 *this)
{
  unsigned __int16 *v1; // eax
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax
  vostok::math::half v5; // [esp+2Ch] [ebp-Ch] BYREF
  unsigned __int16 v6; // [esp+2Eh] [ebp-Ah]
  vostok::math::half v7; // [esp+30h] [ebp-8h] BYREF
  unsigned __int16 v8; // [esp+32h] [ebp-6h]
  vostok::math::half v9; // [esp+34h] [ebp-4h] BYREF
  unsigned __int16 v10; // [esp+36h] [ebp-2h]

  vostok::math::half::half(&v9, 0.0);
  v10 = *v1;
  this->m_data.m_val.x.data = v10;
  vostok::math::half::half(&v7, 0.0);
  v8 = *v2;
  this->m_data.m_val.y.data = v8;
  vostok::math::half::half(&v5, 0.0);
  v6 = *v3;
  this->m_data.m_val.z.data = v6;
}
