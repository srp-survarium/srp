void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorGet(
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this,
        unsigned int *result)
{
  *result = (unsigned __int8)(int)this->blueOffset
          | (((unsigned __int8)(int)this->greenOffset | ((unsigned __int8)(int)this->redOffset << 8)) << 8);
}
