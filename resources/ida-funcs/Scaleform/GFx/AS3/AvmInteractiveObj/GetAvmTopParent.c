Scaleform::GFx::AS3::AvmInteractiveObj *__thiscall Scaleform::GFx::AS3::AvmInteractiveObj::GetAvmTopParent(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        BOOL ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  int v3; // eax
  int v4; // eax

  pParent = this->pDispObj->pParent;
  if ( pParent->pASRoot->AVMVersion == 2
    && (v3 = (int)pParent->GetTopParent(pParent, ignoreLockRoot),
        (v4 = (*(int (__thiscall **)(int))(*(_DWORD *)(v3 + 4 * *(unsigned __int8 *)(v3 + 65)) + 4))(v3 + 4 * *(unsigned __int8 *)(v3 + 65))) != 0) )
  {
    return (Scaleform::GFx::AS3::AvmInteractiveObj *)(v4 - 28);
  }
  else
  {
    return 0;
  }
}
