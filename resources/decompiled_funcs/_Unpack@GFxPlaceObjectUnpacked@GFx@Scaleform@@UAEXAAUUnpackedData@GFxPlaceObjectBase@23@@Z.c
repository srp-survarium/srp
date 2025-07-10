void __thiscall Scaleform::GFx::GFxPlaceObjectUnpacked::Unpack(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  data->Name = 0;
  data->pEventHandlers = 0;
  data->PlaceType = Place_Add;
  Scaleform::GFx::CharPosInfo::operator=(&data->Pos, &this->Pos);
}
