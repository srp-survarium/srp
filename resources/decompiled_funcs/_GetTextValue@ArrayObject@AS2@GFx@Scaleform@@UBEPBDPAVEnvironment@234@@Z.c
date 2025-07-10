const survarium::flash_text *__thiscall Scaleform::GFx::AS2::ArrayObject::GetTextValue(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *pEnv)
{
  Scaleform::ArrayDefaultPolicy *p_Policy; // esi
  unsigned int v5; // edi
  Scaleform::StringBuffer sbuffer; // [esp+Ch] [ebp-18h] BYREF

  ++this->Elements.Data.Data;
  p_Policy = &this[-1].Elements.Data.Policy;
  if ( (int)this->Elements.Data.Data < 255 )
  {
    Scaleform::StringBuffer::StringBuffer(&sbuffer, pEnv->StringContext.pContext->pHeap);
    Scaleform::GFx::AS2::ArrayObject::JoinToString((Scaleform::GFx::AS2::ArrayObject *)p_Policy, pEnv, &sbuffer, ",");
    Scaleform::String::operator=((Scaleform::String *)&this->LogPtr, &sbuffer);
    v5 = (int)this->LogPtr & 0xFFFFFFFC;
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sbuffer);
    --p_Policy[18].Capacity;
    return (const survarium::flash_text *)(v5 + 8);
  }
  else
  {
    Scaleform::GFx::LogState::LogMessageByType(
      (Scaleform::GFx::LogState *)p_Policy[13].Capacity,
      (Scaleform::LogMessageId)&loc_34000,
      "256 levels of recursion is reached\n");
    --p_Policy[18].Capacity;
    return &buf;
  }
}
