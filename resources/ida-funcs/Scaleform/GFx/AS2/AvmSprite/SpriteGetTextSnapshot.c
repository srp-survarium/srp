void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGetTextSnapshot(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::Sprite *Target; // ebx
  Scaleform::GFx::Sprite *v3; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::TextSnapshotObject *v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      v3 = (Scaleform::GFx::Sprite *)ThisPtr[1].__vftable;
    else
      v3 = 0;
    Target = v3;
  }
  else
  {
    Target = (Scaleform::GFx::Sprite *)fn->Env->Target;
  }
  if ( Target )
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v5 = (Scaleform::GFx::AS2::TextSnapshotObject *)pHeap->Alloc(pHeap, 72u, 0);
    if ( v5 )
    {
      Scaleform::GFx::AS2::TextSnapshotObject::TextSnapshotObject(v5, fn->Env);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    Scaleform::GFx::Sprite::GetTextSnapshot(Target, (Scaleform::GFx::StaticTextSnapshotData *)(v7 + 52));
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)v7);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 12);
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(v7 + 12) = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
      }
    }
  }
}
