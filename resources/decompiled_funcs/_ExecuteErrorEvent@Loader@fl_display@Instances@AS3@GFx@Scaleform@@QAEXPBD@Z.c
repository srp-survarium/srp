void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        const char *url)
{
  char buf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( this->pContentLoaderInfo.pObject )
  {
    Scaleform::SFsprintf(buf, 0x400u, "Error reading %s", url);
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this->pContentLoaderInfo.pObject,
      buf);
  }
}
