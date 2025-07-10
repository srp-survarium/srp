char __cdecl Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType(
        Scaleform::GFx::MovieImpl *proot,
        unsigned int mouseIndex,
        unsigned int cursorType)
{
  Scaleform::GFx::UserEventHandler *pObject; // ecx
  int v5; // [esp+0h] [ebp-10h] BYREF
  char v6; // [esp+4h] [ebp-Ch]
  unsigned int v7; // [esp+8h] [ebp-8h]
  unsigned int v8; // [esp+Ch] [ebp-4h]

  pObject = proot->pUserEventHandler.pObject;
  if ( !pObject )
    return 0;
  v7 = cursorType;
  v6 = 0;
  v5 = 23;
  v8 = mouseIndex;
  pObject->HandleEvent(pObject, proot, (const Scaleform::GFx::Event *)&v5);
  return 1;
}
