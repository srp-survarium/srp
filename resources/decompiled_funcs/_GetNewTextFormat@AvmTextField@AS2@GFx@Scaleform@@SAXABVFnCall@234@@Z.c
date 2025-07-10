void __usercall Scaleform::GFx::AS2::AvmTextField::GetNewTextFormat(
        int a1@<edi>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v3; // eax
  int v4; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::Text::TextFormat *v6; // ebx
  Scaleform::Render::Text::ParagraphFormat *v7; // ebp
  Scaleform::GFx::AS2::TextFormatObject *v8; // eax
  Scaleform::GFx::AS2::TextFormatObject *v9; // eax
  Scaleform::GFx::AS2::TextFormatObject *v10; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // esi

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    if ( (unsigned int)(((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, int))ThisPtr->GetObjectType)(
                          ThisPtr,
                          a1)
                      - 2) > 3 )
      v3 = 0;
    else
      v3 = ThisPtr[1].__vftable;
    v4 = *((_DWORD *)v3[1].GetMemberRaw + 2);
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v6 = *(Scaleform::Render::Text::TextFormat **)(v4 + 28);
    v7 = *(Scaleform::Render::Text::ParagraphFormat **)(v4 + 24);
    v8 = (Scaleform::GFx::AS2::TextFormatObject *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))pHeap->Alloc)(
                                                    pHeap,
                                                    112);
    if ( v8 )
    {
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v8, fn->Env);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( v6 )
      Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(v10, &fn->Env->StringContext, v6);
    if ( v7 )
      Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(v10, (signed int)&fn->Env->StringContext, v7);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v10);
    if ( v10 )
    {
      RefCount = v10->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v10->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
  }
}
