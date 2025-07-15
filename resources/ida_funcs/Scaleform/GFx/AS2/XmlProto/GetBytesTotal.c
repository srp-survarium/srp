void __cdecl Scaleform::GFx::AS2::XmlProto::GetBytesTotal(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  double *p_pProto; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  double v4; // [esp+4h] [ebp-8h]

  if ( Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (double *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        Result = fn->Result;
        if ( p_pProto[9] >= 0.0 )
        {
          v4 = p_pProto[9];
          if ( Result->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->T.Type = 3;
          Result->NV.NumberValue = v4;
        }
        else
        {
          Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->T.Type = 0;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XML", 0, 0);
  }
}
