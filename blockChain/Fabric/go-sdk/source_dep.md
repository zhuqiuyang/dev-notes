```go
"github.com/hyperledger/fabric-sdk-go/pkg/common/providers/fab"

type Client fab.ClientContext

type ClientContext interface {
	core.Providers
	msp.Providers
	Providers
	msp.SigningIdentity
}

type Providers interface {
	LocalDiscoveryProvider() LocalDiscoveryProvider
	ChannelProvider() ChannelProvider
	InfraProvider() InfraProvider
	EndpointConfig() EndpointConfig
}

type ChannelProvider interface {
	ChannelService(ctx ClientContext, channelID string) (ChannelService, error)
}

type ChannelService interface {
  Config() (ChannelConfig, error)
  // 包含 channelService
	EventService(opts ...options.Opt) (EventService, error)
	Membership() (ChannelMembership, error)
	ChannelConfig() (ChannelCfg, error)
	Transactor(reqCtx reqContext.Context) (Transactor, error)
	Discovery() (DiscoveryService, error)
	Selection() (SelectionService, error)
}
```
