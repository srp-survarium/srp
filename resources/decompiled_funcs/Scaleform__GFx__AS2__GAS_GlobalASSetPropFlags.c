void __cdecl Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags(Scaleform::GFx::AS2::ObjectInterface *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *v2; // eax
  unsigned int pObject; // edx
  int v4; // edi
  int v5; // ebx
  Scaleform::GFx::AS2::Value *v6; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v7; // eax
  const Scaleform::GFx::AS2::FnCall *v8; // ebx
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::Environment *Env; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // edi
  unsigned __int8 Type; // al
  Scaleform::GFx::ASStringNode **v14; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::ArrayObject *v16; // ecx
  Scaleform::GFx::ASStringNode *v17; // ecx
  bool v18; // zf
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::AS2::Object *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v22; // ebx
  _DWORD *v23; // edx
  unsigned int v24; // eax
  Scaleform::GFx::AS2::Value *v25; // ecx
  unsigned __int8 v26; // cl
  char v27; // al
  Scaleform::GFx::ASStringNode **v28; // eax
  unsigned int v29; // edx
  Scaleform::GFx::AS2::ArrayObject *v30; // ecx
  Scaleform::GFx::ASStringNode *v31; // ecx
  Scaleform::GFx::AS2::Value *v32; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pNode; // ebp
  unsigned __int8 v34; // al
  int p_StringContext; // edi
  void (__thiscall *v36)(struct Scaleform::GFx::AS2::FnCall *); // edx
  unsigned int v37; // ecx
  int v38; // eax
  Scaleform::GFx::AS2::Value *v39; // ecx
  bool (__thiscall *IsVerboseActionErrors)(struct Scaleform::GFx::AS2::FnCall *); // edx
  Scaleform::GFx::ASStringNode *v41; // eax
  unsigned int v42; // eax
  Scaleform::GFx::AS2::Environment *v43; // [esp+0h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v44; // [esp+0h] [ebp-3Ch]
  Scaleform::GFx::AS2::Environment *v45; // [esp+4h] [ebp-38h]
  unsigned __int8 setFalse; // [esp+17h] [ebp-25h]
  Scaleform::GFx::ASString key; // [esp+18h] [ebp-24h] BYREF
  int i; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> result; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> v50; // [esp+24h] [ebp-18h] BYREF
  int n; // [esp+28h] [ebp-14h]
  Scaleform::GFx::AS2::Member member; // [esp+2Ch] [ebp-10h] BYREF

  v1 = (const Scaleform::GFx::AS2::FnCall *)fn;
  v2 = (Scaleform::GFx::AS2::Environment *)fn[2].__vftable;
  pObject = (unsigned int)fn[2].pProto.pObject;
  v4 = v2->Stack.pCurrent - v2->Stack.pPageStart;
  v5 = 32 * (v2->Stack.Pages.Data.Size - 1);
  n = v2->StringContext.SWFVersion;
  v6 = 0;
  if ( pObject <= v5 + v4 )
    v6 = &v2->Stack.Pages.Data.Data[pObject >> 5]->Values[pObject & 0x1F];
  v45 = (Scaleform::GFx::AS2::Environment *)fn[2].__vftable;
  if ( v6->T.Type == 7 )
  {
    v7 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v6, v45);
    if ( !v7 )
      return;
    v8 = (const Scaleform::GFx::AS2::FnCall *)&v7->Scaleform::GFx::AS2::ObjectInterface;
    fn = &v7->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    v9 = Scaleform::GFx::AS2::Value::ToObject(v6, v45);
    if ( !v9 )
      return;
    fn = &v9->Scaleform::GFx::AS2::ObjectInterface;
    v8 = (const Scaleform::GFx::AS2::FnCall *)&v9->Scaleform::GFx::AS2::ObjectInterface;
  }
  if ( v8 )
  {
    Env = v1->Env;
    v11 = v1->FirstArgBottomIndex - 1;
    v12 = 0;
    if ( v11 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v12 = &Env->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
    Type = v12->T.Type;
    key.pNode = 0;
    switch ( Type )
    {
      case 5u:
        Scaleform::GFx::AS2::Value::ToStringImpl(v12, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
        v14 = (Scaleform::GFx::ASStringNode **)Scaleform::GFx::AS2::StringProto::StringSplit(
                                                 &result,
                                                 v1->Env,
                                                 (const Scaleform::GFx::ASString *)&fn,
                                                 ",",
                                                 (Scaleform::String)0x3FFFFFFF);
        if ( *v14 )
          (*v14)->RefCount = ((*v14)->RefCount + 1) & 0x8FFFFFFF;
        key.pNode = *v14;
        if ( result.pObject )
        {
          RefCount = result.pObject->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v16 = result.pObject;
            result.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
          }
        }
        v17 = (Scaleform::GFx::ASStringNode *)fn;
        v18 = fn[1].__vftable-- == (Scaleform::GFx::AS2::ObjectInterface_vtbl *)1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        break;
      case 6u:
        v43 = Env;
        v19 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
        v20 = Scaleform::GFx::AS2::Value::ToObject(v19, v43);
        v21 = (Scaleform::GFx::ASStringNode *)v20;
        if ( v20 )
        {
          v22 = &v20->Scaleform::GFx::AS2::ObjectInterface;
          if ( v20->GetObjectType(&v20->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
          {
            v21->RefCount = (v21->RefCount + 1) & 0x8FFFFFFF;
            key.pNode = v21;
          }
          else
          {
            if ( v22->GetObjectType((Scaleform::GFx::AS2::ObjectInterface *)&v21->HashFlags) != Object_String )
              return;
            Scaleform::GFx::AS2::Value::ToStringImpl(v12, (Scaleform::GFx::ASString *)&i, v1->Env, -1, 0);
            v28 = (Scaleform::GFx::ASStringNode **)Scaleform::GFx::AS2::StringProto::StringSplit(
                                                     &v50,
                                                     v1->Env,
                                                     (const Scaleform::GFx::ASString *)&i,
                                                     ",",
                                                     (Scaleform::String)0x3FFFFFFF);
            if ( *v28 )
              (*v28)->RefCount = ((*v28)->RefCount + 1) & 0x8FFFFFFF;
            key.pNode = *v28;
            if ( v50.pObject )
            {
              v29 = v50.pObject->RefCount;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v29) != 0 )
              {
                v30 = v50.pObject;
                v50.pObject->RefCount = v29 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
              }
            }
            v31 = (Scaleform::GFx::ASStringNode *)i;
            v18 = (*(_DWORD *)(i + 12))-- == 1;
            if ( v18 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
          }
          v8 = (const Scaleform::GFx::AS2::FnCall *)fn;
        }
        break;
      case 1u:
        break;
      default:
        return;
    }
    v23 = &v1->Env->__vftable;
    v24 = v1->FirstArgBottomIndex - 2;
    v25 = 0;
    if ( v24 <= 32 * (v23[6] - 1) + ((v23[1] - v23[2]) >> 4) )
      v25 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v23[5] + 4 * (v24 >> 5)) + 16 * (v24 & 0x1F));
    v26 = Scaleform::GFx::AS2::Value::ToInt32(v25, v1->Env) & 7;
    v18 = v1->NArgs == 3;
    LOBYTE(fn) = v26;
    if ( v18 )
    {
      v27 = (n != 5) - 1;
    }
    else
    {
      v44 = v1->Env;
      v32 = Scaleform::GFx::AS2::FnCall::Arg(v1, 3);
      v27 = Scaleform::GFx::AS2::Value::ToUInt32(v32, v44);
      v26 = (unsigned __int8)fn;
    }
    pNode = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)key.pNode;
    v34 = v27 & 7;
    p_StringContext = (int)&v1->Env->StringContext;
    setFalse = v34;
    if ( key.pNode )
    {
      v37 = key.pNode[2].RefCount;
      v38 = 0;
      i = 0;
      for ( n = v37; i < n; ++i )
      {
        v39 = *(Scaleform::GFx::AS2::Value **)(pNode[3].RootIndex + 4 * v38);
        if ( v39 )
        {
          Scaleform::GFx::AS2::Value::ToStringImpl(v39, &key, v1->Env, -1, 0);
          IsVerboseActionErrors = v8->__vftable[2].IsVerboseActionErrors;
          member.mValue.T = 0;
          if ( ((unsigned __int8 (__thiscall *)(const Scaleform::GFx::AS2::FnCall *, int, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))IsVerboseActionErrors)(
                 v8,
                 p_StringContext,
                 &key,
                 &member) )
          {
            ((void (__thiscall *)(const Scaleform::GFx::AS2::FnCall *, int, Scaleform::GFx::ASString *, int))v8->__vftable[3].IsVerboseActionErrors)(
              v8,
              p_StringContext,
              &key,
              (unsigned __int8)fn | (unsigned __int8)(member.mValue.T.PropFlags & ~setFalse));
          }
          if ( member.mValue.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&member.mValue);
          v41 = key.pNode;
          --key.pNode->RefCount;
          if ( !v41->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v41);
        }
        v38 = i + 1;
      }
      v42 = pNode->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v42) != 0 )
      {
        pNode->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pNode);
      }
    }
    else
    {
      member.mValue.V.FunctionValue.Flags = v26;
      *((_BYTE *)&member.mValue.NV + 13) = v34;
      v36 = v8->__vftable[4].~Scaleform::GFx::AS2::FnCall;
      *(_DWORD *)&member.mValue.T.Type = &`Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags'::`27'::MemberVisitor::`vftable';
      *(_QWORD *)&member.mValue.NV.NumberValue = __PAIR64__(p_StringContext, (unsigned int)v8);
      ((void (__thiscall *)(const Scaleform::GFx::AS2::FnCall *, int, Scaleform::GFx::AS2::Member *, int, _DWORD))v36)(
        v8,
        p_StringContext,
        &member,
        12,
        0);
    }
  }
}
