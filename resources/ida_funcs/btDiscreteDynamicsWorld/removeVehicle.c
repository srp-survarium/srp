void __thiscall btDiscreteDynamicsWorld::removeVehicle(btDiscreteDynamicsWorld *this, btActionInterface *vehicle)
{
  this->removeAction(this, vehicle);
}
