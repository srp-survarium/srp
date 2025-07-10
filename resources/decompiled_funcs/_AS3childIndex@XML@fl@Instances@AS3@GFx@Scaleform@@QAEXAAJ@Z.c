void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3childIndex(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        int *result)
{
  int *v2; // esi
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v2 = result;
  *result = -1;
  if ( this->GetChildIndex(this, &result, &ind)->Result )
    *v2 = ind;
}
