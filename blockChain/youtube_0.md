### Building a blockchain for business with the Hyperledger Project
> https://www.youtube.com/watch?v=EKa5Gh9whgU

Fabric: developer candidate(开发者候选)
* Supply chain(供应链)
* Capital market(资本市场)
* Manufacturing(制造业)
* HealthCare(医疗)

#### What we learned?

GOAL: modular, scable, secure

Peer: Endorser(背书节点), Commiter()
Consenter: Consenter(同意者)

#### How it works ?
问题: 
> Market(我)以低价买萝卜, 而其他marktet以标准价

Fabric 解决了: 
> 更多的party(监管, 海关)参与, 但不会了解到special low price.


**Without** passing everything through a **central authority**


> Hyperledger® is one of the fastest growing open source blockchain communities. Anyone can help lead it. Learn more and join the community: www.hyperledger.org. Or, head here, http://ibm.co/2dbtffw.

> The work started last year with a simple framework to test the interaction between applications and secure blockchain networks, and it’s allowed us to test use cases in supply chain, capital markets, manufacturing, and healthcare.

> First, we learned that permissioned blockchain networks that require every peer to execute every transaction, maintain a ledger and run consensus can’t scale very well and can’t support true private transactions and confidential contracts. So the community designed Hyperledger Fabric™ V1 to deliver a truly modular, scalable, and secure foundation for industrial blockchain solutions. That’s what we’re building right now and we could use your help.

> The most notable change is that peers are now “decoupled” into two separate runtimes with three distinct roles: `Endorser, Committer, and Consenter`. **Example**: Pretend you run an organic market in California and I grow radishes on my farm in Chile. You and I are on a blockchain network that supports transactions between various markets, growers, shippers, banks, and others.

> I agree to sell you my radishes at a special low price. But I need the other markets that buy from me to continue buying at the standard price — they shouldn’t be able to execute our **confidential** agreement and find out the details of our deal. In fact, if they aren’t part of the deal, the transaction shouldn’t even appear on the ledger.

> Hyperledger Fabric™ V1 handles all this. My app looks up your identity(身份) from a membership service and then sends the transaction only to our peers. Both of our peers will generate a result. In this two-party(双方的) agreement, the transaction requires both of us to render the same result, but in transactions with more parties, other rules can apply. Then the peers send the validated transaction back to the application, which sends it to a consensus cloud for ordering. And then the ordered transactions are sent back to the peers and committed to the ledger.

> But to get my radishes to your market, there are many other parties involved and so now we have to run different transactions with different parties — some need to know that [my radishes have been verified and checked into a shipping container and that the temperature of the container never exceeds a maximum set by our transit(运输) agreement]

> Others need to [handle bills of lading, customs inspections, financing, and insurance], but most of these parties don’t need to know about our `special price agreement`. Hyperledger Fabric™ V1 delivers one network with everyone working together while ensuring confidentiality, scalability, and security.

> Now think about our transaction running on a network handling all the markets and all the farms, shippers, and facilitators in the supply chain. And imagine where this goes … this is the same pattern needed by many industries … anywhere we need to manage confidential obligations to each other without passing everything through a central authority.

> So, how do we get there? Go to hyperledger.org to find out.

> For Hyperledger Fabric™ V1 documentation, visit: http://hyperledger-fabric.readthedocs.io/en/latest/abstract_v1/
