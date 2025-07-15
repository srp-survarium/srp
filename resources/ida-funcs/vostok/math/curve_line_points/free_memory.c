void __usercall vostok::math::curve_line_points<float,0>::free_memory(
        vostok::math::curve_line_points<float,0> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  if ( *(_DWORD *)(a2 + 24) )
  {
    v2 = *(_DWORD *)(a2 + 16);
    if ( v2 )
      (*(void (__thiscall **)(vostok::math::curve_line_points<float,0> *, int, const char *, const char *, int))(LODWORD(this->curve_time_min) + 24))(
        this,
        v2,
        "vostok::math::curve_line_points<float,0>::free_memory",
        "c:\\survarium.deploy\\sources\\vostok\\math_curve_inline.h",
        329);
    *(_DWORD *)(a2 + 16) = 0;
    *(_DWORD *)(a2 + 24) = 0;
  }
}


void __usercall vostok::math::curve_line_points<vostok::math::float3_pod,0>::free_memory(
        vostok::math::curve_line_points<vostok::math::float3_pod,0> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  if ( *(_DWORD *)(a2 + 40) )
  {
    v2 = *(_DWORD *)(a2 + 32);
    if ( v2 )
      (*(void (__thiscall **)(vostok::math::curve_line_points<vostok::math::float3_pod,0> *, int, const char *, const char *, int))(LODWORD(this->curve_time_min) + 24))(
        this,
        v2,
        "vostok::math::curve_line_points<class vostok::math::float3_pod,0>::free_memory",
        "c:\\survarium.deploy\\sources\\vostok\\math_curve_inline.h",
        329);
    *(_DWORD *)(a2 + 32) = 0;
    *(_DWORD *)(a2 + 40) = 0;
  }
}


void __usercall vostok::math::curve_line_points<vostok::math::float4_pod,1>::free_memory(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  if ( *(_DWORD *)(a2 + 48) )
  {
    v2 = *(_DWORD *)(a2 + 40);
    if ( v2 )
      (*(void (__thiscall **)(vostok::math::curve_line_points<vostok::math::float4_pod,1> *, int, const char *, const char *, int))(LODWORD(this->curve_time_min) + 24))(
        this,
        v2,
        "vostok::math::curve_line_points<class vostok::math::float4_pod,1>::free_memory",
        "c:\\survarium.deploy\\sources\\vostok\\math_curve_inline.h",
        329);
    *(_DWORD *)(a2 + 40) = 0;
    *(_DWORD *)(a2 + 48) = 0;
  }
}
