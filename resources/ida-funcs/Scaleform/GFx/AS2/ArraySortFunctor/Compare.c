int __thiscall Scaleform::GFx::AS2::ArraySortFunctor::Compare(
        Scaleform::GFx::AS2::ArraySortFunctor *this,
        Scaleform::GFx::AS2::Value *a,
        Scaleform::GFx::AS2::Value *b)
{
  Scaleform::GFx::AS2::Value *v3; // ebx
  Scaleform::GFx::AS2::Value *v5; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  Scaleform::GFx::AS2::Value *pCurrent; // edi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v10; // edi
  Scaleform::GFx::AS2::Value *v11; // edi
  Scaleform::GFx::AS2::Environment *v12; // eax
  int v13; // ecx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  int v16; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v17; // edi
  int v18; // eax
  int v19; // esi
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // edi
  bool v23; // al
  double v24; // st7
  char v25; // bl
  Scaleform::GFx::ASStringNode *v26; // edi
  bool v27; // al
  int v28; // ecx
  int Flags; // eax
  char *v30; // edi
  unsigned int Length; // eax
  int v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  char v35; // [esp-4h] [ebp-68h]
  Scaleform::GFx::ASStringNode *v36; // [esp+14h] [ebp-50h] BYREF
  double v37; // [esp+18h] [ebp-4Ch] BYREF
  Scaleform::GFx::AS2::Value v38; // [esp+20h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value v39; // [esp+30h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v40; // [esp+40h] [ebp-24h] BYREF

  v3 = a;
  v39.T.Type = 0;
  if ( !a )
  {
    a = &v39;
    v3 = &v39;
  }
  v5 = b;
  if ( !b )
    v5 = &v39;
  if ( !this->Func.Function )
  {
    v21 = (this->Flags & 0x10) == 0;
    *(double *)&v38.T.Type = 0.0;
    v37 = 0.0;
    if ( !v21 )
    {
      if ( v3->T.Type == 3 || v3->T.Type == 4 )
      {
        *(double *)&v38.T.Type = Scaleform::GFx::AS2::Value::ToNumber(v3, this->Env);
        LOBYTE(b) = 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&b, this->Env, -1, 0);
        v22 = (Scaleform::GFx::ASStringNode *)b;
        v23 = Scaleform::GFx::AS2::GAS_ParseNumber(*(char **)&b->T.Type, (int)b, (long double *)&v38.T.Type);
        v21 = v22->RefCount-- == 1;
        LOBYTE(b) = v23;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      }
      if ( v5->T.Type == 3 || v5->T.Type == 4 )
      {
        v24 = Scaleform::GFx::AS2::Value::ToNumber(v5, this->Env);
        v25 = 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v36, this->Env, -1, 0);
        v26 = v36;
        v27 = Scaleform::GFx::AS2::GAS_ParseNumber((char *)v36->pData, (int)v36, &v37);
        v21 = v26->RefCount-- == 1;
        v25 = v27;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        v24 = v37;
      }
      if ( (_BYTE)b && v25 )
      {
        if ( *(double *)&v38.T.Type >= v24 )
          v28 = 0;
        else
          v28 = -1;
        if ( *(double *)&v38.T.Type > v24 )
          v28 = 1;
        if ( (this->Flags & 2) != 0 )
          return -v28;
        return v28;
      }
      v3 = a;
    }
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&b, this->Env, -1, 0);
    Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&a, this->Env, -1, 0);
    Flags = this->Flags;
    if ( (Flags & 0x400) != 0 )
    {
      v30 = *(char **)&a->T.Type;
      LOBYTE(v36) = (Flags & 1) == 0;
      v35 = (char)v36;
      Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&a);
      v32 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
              (Scaleform::GFx::ASConstString *)&b,
              v30,
              Length,
              v35);
    }
    else if ( (Flags & 1) != 0 )
    {
      v32 = Scaleform::String::CompareNoCase(*(char **)&b->T.Type, *(char **)&a->T.Type);
    }
    else
    {
      v32 = strcmp(*(const char **)&b->T.Type, *(const char **)&a->T.Type);
    }
    if ( (this->Flags & 2) != 0 )
      v32 = -v32;
    v19 = v32;
    v33 = (Scaleform::GFx::ASStringNode *)a;
    --*((_DWORD *)&a->NV + 3);
    if ( !v33->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    v34 = (Scaleform::GFx::ASStringNode *)b;
    --*((_DWORD *)&b->NV + 3);
    if ( !v34->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    return v19;
  }
  p_Stack = &this->Env->Stack;
  v38.T.Type = 0;
  if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  pCurrent = p_Stack->pCurrent;
  if ( pCurrent )
    Scaleform::GFx::AS2::Value::Value(pCurrent, v5);
  Env = this->Env;
  v9 = ++Env->Stack.pCurrent;
  v10 = &Env->Stack;
  if ( v9 >= v10->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v10);
  v11 = v10->pCurrent;
  if ( v11 )
    Scaleform::GFx::AS2::Value::Value(v11, v3);
  v12 = this->Env;
  v13 = v12->Stack.pCurrent - v12->Stack.pPageStart + 32 * v12->Stack.Pages.Data.Size - 32;
  v40.Result = &v38;
  v40.ThisPtr = this->This;
  memset(&v40.ThisFunctionRef, 0, 9);
  pLocalFrame = this->Func.pLocalFrame;
  v40.FirstArgBottomIndex = v13;
  Function = this->Func.Function;
  v40.Env = v12;
  v16 = 2;
  v40.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  v40.NArgs = 2;
  Function->Invoke(Function, &v40, pLocalFrame, 0);
  v17 = &this->Env->Stack;
  do
  {
    if ( v17->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v17->pCurrent);
    if ( --v17->pCurrent < v17->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v17);
    --v16;
  }
  while ( v16 );
  if ( v40.Result )
  {
    v18 = Scaleform::GFx::AS2::Value::ToInt32(v40.Result, this->Env);
    if ( (this->Flags & 2) != 0 )
      v18 = -v18;
    v19 = v18;
    Scaleform::GFx::AS2::FnCall::~FnCall(&v40);
    if ( v38.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v38);
    if ( v39.T.Type >= 5u )
    {
      Scaleform::GFx::AS2::Value::DropRefs(&v39);
      return v19;
    }
    return v19;
  }
  Scaleform::GFx::AS2::FnCall::~FnCall(&v40);
  if ( v38.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v38);
  if ( v39.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v39);
  return 0;
}
