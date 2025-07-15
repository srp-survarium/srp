char __thiscall Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::Environment *env,
        Scaleform::GFx::AS2::Value *frameValue,
        Scaleform::GFx::InteractiveObject **pptarget,
        unsigned int *pframeNumber)
{
  unsigned __int8 Type; // al
  Scaleform::GFx::InteractiveObject *Target; // ebx
  char v7; // dl
  int Length; // ebp
  char *v9; // esi
  Scaleform::GFx::ASStringNode *v10; // edi
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // esi
  Scaleform::GFx::ASStringNode *v13; // ecx
  unsigned int *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  long double v17; // st7
  char v18; // [esp+Dh] [ebp-9h]
  __int64 v19; // [esp+Eh] [ebp-8h] BYREF

  Type = frameValue->T.Type;
  Target = env->Target;
  v7 = 0;
  v18 = 0;
  if ( frameValue->T.Type == 5 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(frameValue, (Scaleform::GFx::ASString *)&frameValue, env, -1, 0);
    Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&frameValue);
    v9 = 0;
    if ( Length <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      if ( Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&frameValue, v9) == 58 )
      {
        v10 = Scaleform::GFx::ASConstString::SubstringNode((Scaleform::GFx::ASConstString *)&frameValue, 0, v9);
        ++v10->RefCount;
        LODWORD(v19) = v10;
        Target = Scaleform::GFx::AS2::Environment::FindTarget(env, (const Scaleform::GFx::ASString *)&v19, 0);
        if ( Target )
        {
          if ( (int)v9 < Length )
          {
            v12 = Scaleform::GFx::ASConstString::SubstringNode(
                    (Scaleform::GFx::ASConstString *)&frameValue,
                    v9 + 1,
                    (char *)(Length + 1));
            v12->RefCount += 2;
            v13 = (Scaleform::GFx::ASStringNode *)frameValue;
            v14 = (unsigned int *)(&frameValue->NV + 1);
            --*((_DWORD *)&frameValue->NV + 3);
            if ( !*v14 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v13);
            frameValue = (Scaleform::GFx::AS2::Value *)v12;
            v11 = v12->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
            v11 = v10->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v10);
LABEL_17:
            if ( Target && Target->GetLabeledFrame(Target, *(const char **)&frameValue->T.Type, pframeNumber, 1) )
            {
              v7 = 1;
              v18 = 1;
            }
            else
            {
              v7 = 0;
            }
            v15 = (Scaleform::GFx::ASStringNode *)frameValue;
            --*((_DWORD *)&frameValue->NV + 3);
            if ( !v15->RefCount )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v15);
              v7 = v18;
            }
            if ( v7 )
            {
LABEL_24:
              if ( pptarget )
                *pptarget = Target;
            }
            return v7;
          }
          Target = 0;
        }
        v11 = v10->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      }
      if ( (int)++v9 >= Length )
        goto LABEL_17;
    }
  }
  if ( Type != 6 && (Type == 3 || Type == 4) )
  {
    v17 = Scaleform::GFx::AS2::Value::ToNumber(frameValue, env);
    frameValue = (Scaleform::GFx::AS2::Value *)((unsigned __int16)env | 0xC00);
    v7 = 1;
    *pframeNumber = (__int64)(v17 - 1.0);
    goto LABEL_24;
  }
  return v7;
}
