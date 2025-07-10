Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildBefore(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Value *child1,
        const Scaleform::GFx::AS3::Value *child2)
{
  bool v5; // bl
  bool v6; // bl
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // eax
  unsigned int Size; // edi
  unsigned int v10; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *i; // edx

  v5 = 0;
  if ( (child1->Flags & 0x1F) != 0 && ((child1->Flags & 0x1F) - 12 > 3 || child1->value.VS._1.VInt) )
  {
    v8 = Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(this, child1);
    if ( v8 )
    {
      Size = this->Children.Data.Size;
      v10 = 0;
      if ( Size )
      {
        for ( i = this->Children.Data.Data; i->pObject != v8; ++i )
        {
          if ( ++v10 >= Size )
          {
            v7 = result;
            result->Result = 0;
            return v7;
          }
        }
        v5 = this->InsertChildAt(this, &child2, v10, child2)->Result;
      }
    }
    v7 = result;
    result->Result = v5;
  }
  else
  {
    v6 = this->InsertChildAt(this, &child2, this->Children.Data.Size, child2)->Result;
    v7 = result;
    result->Result = v6;
  }
  return v7;
}
