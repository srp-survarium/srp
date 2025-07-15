void __usercall survarium::artefact_onyx_core::~artefact_onyx_core(
        survarium::artefact_onyx_core *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  survarium::artefact_base *v4; // ecx
  void (__thiscall ***i)(_DWORD, _DWORD); // edi

  v3 = a2 + 2864;
  v4 = *(survarium::artefact_base **)v3;
  *(_DWORD *)(v3 + 4) = *(_DWORD *)v3;
  for ( i = *(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 480);
        i != *(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 484);
        i += 28 )
  {
    (**i)(i, 0);
  }
  *(_DWORD *)(a2 + 484) = *(_DWORD *)(a2 + 480);
  survarium::artefact_base::~artefact_base(v4, a2);
}
