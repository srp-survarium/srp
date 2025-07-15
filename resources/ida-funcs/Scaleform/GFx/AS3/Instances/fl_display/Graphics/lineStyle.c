void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::lineStyle(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        Scaleform::GFx::AS3::Value *result,
        float argc,
        Scaleform::GFx::ASStringNode *argv)
{
  unsigned int v4; // ebp
  Scaleform::GFx::AS3::Value *v6; // esi
  const Scaleform::GFx::AS3::Value *pStringManager; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  const Scaleform::GFx::AS3::Value *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::DrawingContext *pObject; // ecx
  unsigned int scaleMode; // [esp+28h] [ebp-2Ch]
  unsigned int joints; // [esp+2Ch] [ebp-28h]
  unsigned int caps; // [esp+30h] [ebp-24h]
  float miterLimit; // [esp+34h] [ebp-20h]
  bool pixelHinting; // [esp+38h] [ebp-1Ch]
  float alpha; // [esp+3Ch] [ebp-18h]
  unsigned int color; // [esp+44h] [ebp-10h] BYREF
  float thickness; // [esp+48h] [ebp-Ch]
  double r; // [esp+4Ch] [ebp-8h] BYREF

  r = 0.0;
  v4 = LODWORD(argc);
  alpha = 1.0;
  miterLimit = 3.0;
  color = 0;
  pixelHinting = 0;
  scaleMode = 0;
  caps = 0;
  joints = 0;
  if ( argc != 0.0 )
  {
    v6 = (Scaleform::GFx::AS3::Value *)argv;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(
           (Scaleform::GFx::AS3::Value *)argv,
           (Scaleform::GFx::AS3::CheckResult *)&argc,
           &r)->Result )
    {
      thickness = r;
      if ( v4 <= 1
        || Scaleform::GFx::AS3::Value::Convert2UInt32(v6 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &color)->Result )
      {
        if ( v4 > 2 )
        {
          if ( !Scaleform::GFx::AS3::Value::Convert2Number(v6 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &r)->Result )
            return;
          alpha = r;
        }
        if ( v4 > 3 )
          pixelHinting = Scaleform::GFx::AS3::Value::Convert2Boolean(v6 + 3);
        if ( v4 > 4 )
        {
          pStringManager = (const Scaleform::GFx::AS3::Value *)this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
          argv = (Scaleform::GFx::ASStringNode *)&pStringManager[2];
          ++pStringManager[2].value.VS._2.VObj;
          if ( !Scaleform::GFx::AS3::Value::Convert2String(
                  v6 + 4,
                  (Scaleform::GFx::AS3::CheckResult *)&argc,
                  (Scaleform::GFx::ASString *)&argv)->Result )
            goto LABEL_30;
          if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "vertical") )
          {
            scaleMode = 4;
          }
          else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "horizontal") )
          {
            scaleMode = 2;
          }
          else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "none") )
          {
            scaleMode = 6;
          }
          v8 = argv;
          --argv->RefCount;
          if ( !v8->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        }
        if ( v4 > 5 )
        {
          v9 = (const Scaleform::GFx::AS3::Value *)this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
          argv = (Scaleform::GFx::ASStringNode *)&v9[2];
          ++v9[2].value.VS._2.VObj;
          if ( !Scaleform::GFx::AS3::Value::Convert2String(
                  v6 + 5,
                  (Scaleform::GFx::AS3::CheckResult *)&argc,
                  (Scaleform::GFx::ASString *)&argv)->Result )
            goto LABEL_30;
          if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "none") )
          {
            caps = 320;
          }
          else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "square") )
          {
            caps = 640;
          }
          v10 = argv;
          --argv->RefCount;
          if ( !v10->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        }
        if ( v4 > 6 )
        {
          argv = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
          ++argv->RefCount;
          if ( !Scaleform::GFx::AS3::Value::Convert2String(
                  v6 + 6,
                  (Scaleform::GFx::AS3::CheckResult *)&argc,
                  (Scaleform::GFx::ASString *)&argv)->Result )
          {
LABEL_30:
            v11 = argv;
            --argv->RefCount;
            if ( !v11->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v11);
            return;
          }
          if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "miter") )
          {
            joints = 32;
          }
          else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "bevel") )
          {
            joints = 16;
          }
          v12 = argv;
          --argv->RefCount;
          if ( !v12->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        }
        if ( v4 > 7 )
        {
          if ( !Scaleform::GFx::AS3::Value::Convert2Number(v6 + 7, (Scaleform::GFx::AS3::CheckResult *)&argc, &r)->Result )
            return;
          miterLimit = r;
        }
        argv = (Scaleform::GFx::ASStringNode *)(LOWORD(argc) | 0xC00);
        pObject = this->pDrawing.pObject;
        argc = thickness * 20.0;
        Scaleform::GFx::DrawingContext::ChangeLineStyle(
          pObject,
          argc,
          color & 0xFFFFFF | ((unsigned int)(__int64)(alpha * 255.0) << 24),
          pixelHinting,
          scaleMode,
          caps,
          joints,
          miterLimit);
      }
    }
  }
}
