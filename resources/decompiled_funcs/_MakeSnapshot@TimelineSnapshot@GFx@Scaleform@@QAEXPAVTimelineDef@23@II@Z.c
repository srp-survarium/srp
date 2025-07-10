void __thiscall Scaleform::GFx::TimelineSnapshot::MakeSnapshot(
        Scaleform::GFx::TimelineSnapshot *this,
        Scaleform::GFx::TimelineDef *pdef,
        unsigned int startFrame,
        unsigned int endFrame)
{
  unsigned int i; // edi
  unsigned int j; // esi
  int v7; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v8; // [esp+10h] [ebp-4h]

  for ( i = startFrame; i <= endFrame; ++i )
  {
    pdef->GetPlaylist(pdef, (const Scaleform::GFx::TimelineDef::Frame *)&v7, i);
    for ( j = 0; j < v8; ++j )
      (*(void (__thiscall **)(_DWORD, Scaleform::GFx::TimelineSnapshot *, unsigned int))(**(_DWORD **)(v7 + 4 * j) + 24))(
        *(_DWORD *)(v7 + 4 * j),
        this,
        i);
  }
}
