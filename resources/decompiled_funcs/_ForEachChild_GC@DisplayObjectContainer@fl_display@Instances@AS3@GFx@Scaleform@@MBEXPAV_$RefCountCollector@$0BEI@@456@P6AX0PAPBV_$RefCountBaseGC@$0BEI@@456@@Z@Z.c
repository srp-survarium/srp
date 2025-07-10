void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::DisplayObjContainer *pObject; // esi
  unsigned int v6; // edi
  Scaleform::GFx::DisplayObjectBase *ChildAt; // eax
  Scaleform::GFx::DisplayObjectBase *v8; // ecx
  int v9; // edx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // eax
  unsigned int n; // [esp+14h] [ebp+8h]

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(this, prcc, op);
  if ( this->pLoaderInfo.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pLoaderInfo.pObject);
  if ( this->pContextMenu.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pContextMenu.pObject);
  pObject = (Scaleform::GFx::DisplayObjContainer *)this->pDispObj.pObject;
  if ( pObject )
  {
    v6 = 0;
    n = pObject->mDisplayList.DisplayObjectArray.Data.Size;
    if ( n )
    {
      do
      {
        ChildAt = Scaleform::GFx::DisplayObjContainer::GetChildAt(pObject, v6);
        v8 = (ChildAt->Flags & 0x100) != 0 ? ChildAt : 0;
        if ( v8 )
        {
          v9 = *((ChildAt->Flags & 0x100) != 0 ? &ChildAt->AvmObjOffset : (unsigned __int8 *)65);
          v10 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(&v8->RefCount + v9);
          if ( (Scaleform::GFx::DisplayObjectBase *)((char *)v8 + 4 * v9) != (Scaleform::GFx::DisplayObjectBase *)-4
            && ((prcc->Flags & 4) != 0
             || op != Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall
             && op != Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseCall) )
          {
            if ( *v10 )
              op(prcc, v10);
          }
        }
        ++v6;
      }
      while ( v6 < n );
    }
  }
}
