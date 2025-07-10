void __cdecl Scaleform::GFx::AS2::AvmTextField::GetCharBoundaries(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v2; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  unsigned int v4; // eax
  Scaleform::Render::Text::DocView *GetMemberRaw; // ecx
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::RectangleObject *v7; // eax
  Scaleform::GFx::AS2::RectangleObject *v8; // eax
  Scaleform::GFx::AS2::RectangleObject *v9; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *v12; // [esp+48h] [ebp-48h]
  Scaleform::GFx::AS2::Environment *Env; // [esp+4Ch] [ebp-44h]
  float v14; // [esp+5Ch] [ebp-34h]
  Scaleform::Render::Rect<float> pCharRect; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+70h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v2 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : ThisPtr[1].__vftable;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env);
      GetMemberRaw = (Scaleform::Render::Text::DocView *)v2[1].GetMemberRaw;
      pCharRect.x1 = 0.0;
      pCharRect.y1 = 0.0;
      v14 = 0.0 + 0.0;
      pCharRect.x2 = v14;
      pCharRect.y2 = v14;
      if ( Scaleform::Render::Text::DocView::GetCharBoundaries(GetMemberRaw, &pCharRect, v4) )
      {
        pHeap = fn->Env->StringContext.pContext->pHeap;
        v7 = (Scaleform::GFx::AS2::RectangleObject *)pHeap->Alloc(pHeap, 52u, 0);
        if ( v7 )
        {
          Scaleform::GFx::AS2::RectangleObject::RectangleObject(v7, fn->Env);
          v9 = v8;
        }
        else
        {
          v9 = 0;
        }
        v12 = fn->Env;
        r.x1 = pCharRect.x1 * 0.05;
        r.y1 = pCharRect.y1 * 0.05;
        r.x2 = pCharRect.x2 * 0.05;
        r.y2 = 0.05 * pCharRect.y2;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v9, v12, &r);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v9);
        if ( v9 )
        {
          RefCount = v9->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v9->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
          }
        }
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 1;
      }
    }
  }
}
