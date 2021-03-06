
#ifndef MASTERCONTROL_H
#define MASTERCONTROL_H

#include <Urho3D/Urho3D.h>

#include "luckey.h"

namespace Urho3D {
class Node;
class Scene;
}


class MasterControl : public Application
{
    URHO3D_OBJECT(MasterControl, Application);
public:
    MasterControl(Context* context);
    static MasterControl* GetInstance();

    Scene* GetScene() const { return scene_; }


    // Setup before engine initialization. Modifies the engine paramaters.
    virtual void Setup();
    // Setup after engine initialization.
    virtual void Start();
    // Cleanup after the main loop. Called by Application.
    virtual void Stop();
    void Exit();
    void HandleSceneUpdate(StringHash eventType, VariantMap& eventData);

    Vector3 GetCameraPosition() const { return cameraNode_->GetWorldPosition(); }
    Vector3 GetCameraDirection() const { return cameraNode_->GetDirection(); }

    float Sine(const float freq, const float min, const float max, const float shift = 0.0f);
    float Cosine(const float freq, const float min, const float max, const float shift = 0.0f);

private:
    static MasterControl* instance_;
    Scene* scene_;
    Node* cameraNode_;

    BillboardSet* smoke_;

    float SinePhase(float freq, float shift);
};

#endif // MASTERCONTROL_H

