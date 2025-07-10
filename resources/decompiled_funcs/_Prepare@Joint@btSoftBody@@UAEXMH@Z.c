void __thiscall btSoftBody::Joint::Prepare(btSoftBody::Joint *this, float dt, int __formal)
{
  btSoftBody::Body *v4; // ecx

  btSoftBody::Body::activate((btSoftBody::Body *)this, (int)this->m_bodies);
  btSoftBody::Body::activate(v4, (int)&this->m_bodies[1]);
}
