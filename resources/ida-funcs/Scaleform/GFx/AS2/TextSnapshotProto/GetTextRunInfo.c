void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::GetTextRunInfo(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Value *v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // ebx
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ArrayObject *v7; // eax
  Scaleform::GFx::AS2::ArrayObject *v8; // eax
  Scaleform::GFx::AS2::ArrayObject *v9; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-94h]
  Scaleform::GFx::AS2::Environment *v12; // [esp-4h] [ebp-94h]
  unsigned int end; // [esp+18h] [ebp-78h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // [esp+1Ch] [ebp-74h]
  Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor v15; // [esp+20h] [ebp-70h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs >= 2 )
      {
        Env = fn->Env;
        v2 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v3 = Scaleform::GFx::AS2::Value::ToUInt32(v2, Env);
        v12 = fn->Env;
        v4 = v3;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        end = Scaleform::GFx::AS2::Value::ToUInt32(v5, v12);
        pHeap = fn->Env->StringContext.pContext->pHeap;
        v7 = (Scaleform::GFx::AS2::ArrayObject *)pHeap->Alloc(pHeap, 80u, 0);
        if ( v7 )
        {
          Scaleform::GFx::AS2::ArrayObject::ArrayObject(v7, fn->Env);
          v9 = v8;
        }
        else
        {
          v9 = 0;
        }
        Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor::GASTextSnapshotGlyphVisitor(&v15, fn->Env, v9);
        Scaleform::GFx::StaticTextSnapshotData::Visit(
          (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
          &v15,
          v4,
          end);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v9);
        v15.__vftable = (Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        if ( v9 )
        {
          RefCount = v9->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v9->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "TextSnapshot");
  }
}
