void __userpurge Scaleform::GFx::AS3::Class::prototypeGet(
        Scaleform::GFx::AS3::Class *this@<ecx>,
        int a2@<edi>,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *Prototype; // eax

  Prototype = Scaleform::GFx::AS3::Class::GetPrototype(this, a2);
  Scaleform::GFx::AS3::Value::Assign(result, Prototype);
}
