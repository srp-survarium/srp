void __thiscall Scaleform::GFx::ButtonRecord::ButtonRecord(
        Scaleform::GFx::ButtonRecord *this,
        const Scaleform::GFx::ButtonRecord *__that)
{
  Scaleform::Render::FilterSet *pObject; // ecx

  this->ButtonMatrix.M[0][0] = __that->ButtonMatrix.M[0][0];
  this->ButtonMatrix.M[0][1] = __that->ButtonMatrix.M[0][1];
  this->ButtonMatrix.M[0][2] = __that->ButtonMatrix.M[0][2];
  this->ButtonMatrix.M[0][3] = __that->ButtonMatrix.M[0][3];
  this->ButtonMatrix.M[1][0] = __that->ButtonMatrix.M[1][0];
  this->ButtonMatrix.M[1][1] = __that->ButtonMatrix.M[1][1];
  this->ButtonMatrix.M[1][2] = __that->ButtonMatrix.M[1][2];
  this->ButtonMatrix.M[1][3] = __that->ButtonMatrix.M[1][3];
  qmemcpy(&this->ButtonCxform, &__that->ButtonCxform, sizeof(this->ButtonCxform));
  pObject = __that->pFilters.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
  this->pFilters.pObject = __that->pFilters.pObject;
  this->CharacterId.Id = __that->CharacterId.Id;
  this->Depth = __that->Depth;
  this->BlendMode = __that->BlendMode;
  this->Flags = __that->Flags;
}
