void __usercall Scaleform::GFx::AS2::SharedObjectProto::Clear(
        Scaleform::GFx::ASStringNode *a1@<ebx>,
        int a2@<ebp>,
        Scaleform::RefCountNTSImpl *fn)
{
  Scaleform::RefCountNTSImpl_vtbl *v4; // edi
  Scaleform::GFx::AS2::SharedObject *v5; // edi
  Scaleform::GFx::AS2::Object *v6; // ebp
  int v7; // ecx
  Scaleform::RefCountVImpl *v8; // ebx
  int v9; // ecx
  Scaleform::RefCountVImpl *v10; // ebp
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v14; // [esp+14h] [ebp-4h]
  Scaleform::RefCountNTSImpl *v15; // [esp+1Ch] [ebp+4h]

  if ( fn[1].__vftable
    && (*((int (__thiscall **)(Scaleform::RefCountNTSImpl_vtbl *))fn[1].~Scaleform::RefCountNTSImpl + 2))(fn[1].__vftable) == 44 )
  {
    v4 = fn[1].__vftable;
    if ( v4 )
    {
      v5 = (Scaleform::GFx::AS2::SharedObject *)&v4[-4];
      if ( v5 )
      {
        v6 = Scaleform::GFx::AS2::Environment::OperatorNew(
               (Scaleform::GFx::AS2::Environment *)fn[3].__vftable,
               *((Scaleform::GFx::AS2::Object **)fn[3].__vftable[29].~Scaleform::RefCountNTSImpl + 12),
               (const Scaleform::GFx::ASString *)(*(_DWORD *)(*((_DWORD *)fn[3].__vftable[29].~Scaleform::RefCountNTSImpl
                                                              + 5)
                                                            + 12)
                                                + 168),
               0,
               -1);
        v14 = v6;
        Scaleform::GFx::AS2::SharedObject::SetDataObject(v5, (Scaleform::GFx::ASStringNode *)fn[3].__vftable, v6);
        v7 = *(_DWORD *)(*((_DWORD *)fn[3].__vftable[28].~Scaleform::RefCountNTSImpl + 4) + 8);
        v8 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v7 + 8) + 12))(v7 + 8, 32);
        if ( v8 )
        {
          v9 = *(_DWORD *)(*((_DWORD *)fn[3].__vftable[28].~Scaleform::RefCountNTSImpl + 4) + 8);
          v10 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v9 + 8) + 12))(v9 + 8, 9);
          v15 = (Scaleform::RefCountNTSImpl *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *, Scaleform::RefCountVImpl *))v8->Release)(
                                                v8,
                                                &v5->Name,
                                                &v5->LocalPath,
                                                v10);
          if ( v10 )
            Scaleform::RefCountImpl::Release(v10);
          Scaleform::GFx::AS2::SharedObject::Flush(
            v5,
            (int)v10,
            (int)fn,
            (Scaleform::GFx::AS2::Environment *)fn[3].__vftable,
            (Scaleform::GFx::ASStringNode *)v15,
            a2,
            a1);
          if ( v15 )
            Scaleform::RefCountNTSImpl::Release(v15);
          Scaleform::RefCountImpl::Release(v8);
          v6 = v14;
        }
        if ( v6 )
        {
          RefCount = v6->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v6->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)fn[3].__vftable,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "SharedObject");
  }
}
