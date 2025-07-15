void __userpurge vostok::animation::bone_transform::bone_transform(
        const vostok::animation::frame *frame@<edi>,
        vostok::math::quaternion *a2@<ecx>,
        vostok::animation::bone_transform *this,
        bool visibility)
{
  this->translation.x = frame->translation.x;
  this->translation.y = frame->translation.y;
  this->translation.z = frame->translation.z;
  vostok::math::quaternion::quaternion(a2, &this->rotation.x, *(vostok::math::float3 *)&frame->channels[3]);
  this->scale = *(vostok::math::float3 *)&frame->channels[6];
  this->visibility = 1;
}
