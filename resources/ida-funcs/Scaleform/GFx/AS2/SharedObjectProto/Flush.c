void __usercall Scaleform::GFx::AS2::SharedObjectProto::Flush(
        Scaleform::GFx::ASStringNode *a1@<edi>,
        int a2@<esi>,
        Scaleform::RefCountNTSImpl *fn)
{
  Scaleform::RefCountNTSImpl_vtbl *v4; // ebx
  Scaleform::GFx::AS2::SharedObject *v5; // ebx
  int v6; // ecx
  Scaleform::RefCountVImpl *v7; // edi
  int v8; // ecx
  Scaleform::RefCountVImpl *v9; // esi
  Scaleform::RefCountNTSImpl *v12; // [esp+14h] [ebp+4h]

  if ( fn[1].__vftable
    && (*((int (__thiscall **)(Scaleform::RefCountNTSImpl_vtbl *))fn[1].~Scaleform::RefCountNTSImpl + 2))(fn[1].__vftable) == 44 )
  {
    v4 = fn[1].__vftable;
    if ( v4 )
    {
      v5 = (Scaleform::GFx::AS2::SharedObject *)&v4[-4];
      if ( v5 )
      {
        v6 = *(_DWORD *)(*((_DWORD *)fn[3].__vftable[28].~Scaleform::RefCountNTSImpl + 4) + 8);
        v7 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v6 + 8) + 12))(v6 + 8, 32);
        if ( v7 )
        {
          v8 = *(_DWORD *)(*((_DWORD *)fn[3].__vftable[28].~Scaleform::RefCountNTSImpl + 4) + 8);
          v9 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v8 + 8) + 12))(v8 + 8, 9);
          v12 = (Scaleform::RefCountNTSImpl *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *, Scaleform::RefCountVImpl *))v7->Release)(
                                                v7,
                                                &v5->Name,
                                                &v5->LocalPath,
                                                v9);
          if ( v9 )
            Scaleform::RefCountImpl::Release(v9);
          Scaleform::GFx::AS2::SharedObject::Flush(
            v5,
            (int)fn,
            (int)v9,
            (Scaleform::GFx::AS2::Environment *)fn[3].__vftable,
            (Scaleform::GFx::ASStringNode *)v12,
            a2,
            a1);
          if ( v12 )
            Scaleform::RefCountNTSImpl::Release(v12);
          Scaleform::RefCountImpl::Release(v7);
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
