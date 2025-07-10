void __usercall Scaleform::GFx::AS2::PointCtorFunction::Polar(char a1@<bpl>, const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::PointObject *v3; // eax
  Scaleform::GFx::AS2::PointObject *v4; // eax
  Scaleform::GFx::AS2::PointObject *v5; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  int v7; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // eax
  const Scaleform::GFx::AS2::Value *v9; // edx
  Scaleform::GFx::AS2::Environment *v10; // ecx
  int v11; // ebx
  unsigned int Size; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v13; // ecx
  unsigned int v14; // eax
  const Scaleform::GFx::AS2::Value *v15; // edx
  Scaleform::GFx::AS2::Environment *v16; // edx
  unsigned int RefCount; // eax
  long double l; // [esp+8h] [ebp-40h]
  long double a; // [esp+10h] [ebp-38h]
  Scaleform::GFx::AS2::Value angle; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value length; // [esp+28h] [ebp-20h] BYREF
  Scaleform::Render::Point<double> pt; // [esp+38h] [ebp-10h] BYREF

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v3 = (Scaleform::GFx::AS2::PointObject *)pHeap->Alloc(pHeap, 52u, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v3, fn->Env);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  Env = fn->Env;
  if ( fn->NArgs <= 1 )
  {
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, &Env->StringContext, Point_NanParams);
  }
  else
  {
    v7 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
    p_Stack = &Env->Stack;
    v9 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (p_Stack->Pages.Data.Size - 1) + (v7 >> 4) )
      v9 = &p_Stack->Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&length, v9);
    v10 = fn->Env;
    v11 = (char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart;
    Size = v10->Stack.Pages.Data.Size;
    v13 = &v10->Stack;
    v14 = fn->FirstArgBottomIndex - 1;
    v15 = 0;
    if ( v14 <= 32 * (Size - 1) + (v11 >> 4) )
      v15 = &v13->Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
    Scaleform::GFx::AS2::Value::Value(&angle, v15);
    l = Scaleform::GFx::AS2::Value::ToNumber(&length, fn->Env);
    a = Scaleform::GFx::AS2::Value::ToNumber(&angle, fn->Env);
    pt.x = cos(a) * l;
    v16 = fn->Env;
    pt.y = sin(a) * l;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, (int)v5, (int)fn, v16, &pt, a1);
    if ( angle.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&angle);
    if ( length.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&length);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}
